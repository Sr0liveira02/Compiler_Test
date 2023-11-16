#include "../inc/shell.hpp"

Parser::Parser(std::vector<Token> *tokens) {
    _tokens = tokens;
    _i = -1;
    _n_e = true;
    end = false;
    advance();
}

void Parser::advance() {
    _i = _i + 1;
    if (_i < (int)_tokens[0].size())
        _currentToken = _tokens[0][_i];
    else {
        if (_currentToken._tokenType != t_float && _currentToken._tokenType != t_int && _currentToken._tokenType != t_rparen) {
            std::cerr << "Syntax error: Expression must end with a number\n";
            std::cerr << "In File: '" << _currentToken._pos->_fileName << "', line " << (_currentToken._pos->_ln + 1) << "\n";
            _currentToken._pos->write_error_here(1);
            exit(1);
        }
        _currentToken._tokenType = undifined;
        end = true;
    }

}

Node* Parser::factor() {
    // fazer os ifs antes e so depois dar o advance
    Token token = _currentToken;
    if (_currentToken._tokenType == t_lparen) {
        advance();
        Node* pointer = expr();
        if (_currentToken._tokenType == t_rparen) {
            advance();
            return pointer;
        }
        else {
            std::cerr << "Syntax error: Opened parentheses \"(\" and didnt close it\n";
            std::cerr << "In File: '" << _currentToken._pos->_fileName << "', line " << (_currentToken._pos->_ln + 1) << "\n";
            _currentToken._pos->write_error_here(0);
            exit(1);
        }
    }
    if (_currentToken._tokenType == t_minus) {
            advance();
            Node* positive = factor();
            return new Node(uo_neg, positive, _currentToken._pos);
    }
    if (_currentToken._tokenType == t_float || _currentToken._tokenType == t_int) {
        if (!_n_e) {
            std::cerr << "Syntax error: lacks a binary operation here!\n";
            std::cerr << "In File: '" << _currentToken._pos->_fileName << "', line " << (_currentToken._pos->_ln + 1) << "\n";
            _currentToken._pos->write_error_here(-2);
            exit(1);
        }
        _n_e = false;
        advance();
        if (token._tokenType == t_float)
            return new Node(n_float, token._value, token._pos);
        if (token._tokenType == t_int)
            return new Node(n_int, token._value, token._pos);
    }
    return new Node();
}

Node* Parser::term() {
    Node* lNode = factor();
    while (_currentToken._tokenType == t_mul || _currentToken._tokenType == t_div) {
        Token opToken = _currentToken;
        if (_n_e) {
            std::cerr << "Syntax error: lacks a number2 here!\n";
            std::cerr << "In File: '" << _currentToken._pos->_fileName << "', line " << (_currentToken._pos->_ln + 1) << "\n";
            _currentToken._pos->write_error_here(-1);
            exit(1);
        }
        _n_e = true;
        advance();
        Node* rNode = factor();
        if (opToken._tokenType == t_mul)
            lNode = new Node(bo_mul, "\0" , lNode, rNode, opToken._pos);
        if (opToken._tokenType == t_div)
            lNode = new Node(bo_div, "\0" , lNode, rNode, opToken._pos);
    }
    return lNode;
}

Node* Parser::expr() {
    Node* lNode = term();
    while (_currentToken._tokenType == t_plus || _currentToken._tokenType == t_minus) {
        Token opToken = _currentToken;
        if (_n_e) {
            std::cerr << "Syntax error: lacks a number1 here!\n";
            std::cerr << "In File: '" << _currentToken._pos->_fileName << "', line " << (_currentToken._pos->_ln + 1) << "\n";
            _currentToken._pos->write_error_here(-1);
            exit(1);
        }
        _n_e = true;
        advance();
        if (_currentToken._tokenType != t_int && _currentToken._tokenType != t_minus && _currentToken._tokenType != t_float && _currentToken._tokenType != t_lparen) {
            std::cerr << "Syntax error: lacks a number1 here!\n";
            std::cerr << "In File: '" << _currentToken._pos->_fileName << "', line " << (_currentToken._pos->_ln + 1) << "\n";
            _currentToken._pos->write_error_here(0);
            exit(1);
        }
        Node* rNode = term();
        if (opToken._tokenType == t_plus)
            lNode = new Node(bo_plus, "\0" , lNode, rNode, opToken._pos);
        if (opToken._tokenType == t_minus)
            lNode = new Node(bo_minus, "\0" , lNode, rNode, opToken._pos);
    }
    return lNode;
}

Node* Parser::parse() {
    Node* node = expr();
    // ???????????
    if (_i != (int)_tokens[0].size()) {
        node = expr();
    }
    return node;
}