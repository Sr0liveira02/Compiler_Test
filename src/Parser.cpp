#include "../inc/shell.hpp"

Parser::Parser(std::vector<Token> *tokens) {
    _tokens = tokens;
    _i = -1;
    _n_e = true;
    advance();
}

void Parser::advance() {
    _i = _i + 1;
    if (_i < (int)_tokens[0].size())
        _currentToken = _tokens[0][_i];
}

Node* Parser::factor() {
    // fazer os ifs antes e so depois dar o advance
    if (_currentToken._tokenType == t_float || _currentToken._tokenType == t_int) {
        Token token = _currentToken;
        if (!_n_e) {
            std::cerr << "Syntax error!\n";
            exit(1);
        }
        _n_e = false;
        advance();
        if (token._tokenType == t_float)
            return new Node(n_float, token._value);
        if (token._tokenType == t_int)
            return new Node(n_int, token._value);
    }
    return new Node();
}

Node* Parser::term() {
    Node* lNode = factor();
    while (_currentToken._tokenType == t_mul || _currentToken._tokenType == t_div) {
        Token opToken = _currentToken;
        if (_n_e) {
            std::cerr << "Syntax error!\n";
            exit(1);
        }
        _n_e = true;
        advance();
        Node* rNode = factor();
        if (opToken._tokenType == t_mul) {
            lNode = new Node(bo_mul, "\0" , lNode, rNode);
        }
        if (opToken._tokenType == t_div)
            lNode = new Node(bo_div, "\0" , lNode, rNode);
    }
    return lNode;
}

Node* Parser::expr() {
    Node* lNode = term();
    while (_currentToken._tokenType == t_plus || _currentToken._tokenType == t_minus) {
        Token opToken = _currentToken;
        if (_n_e) {
            std::cerr << "Syntax error!\n";
            exit(1);
        }
        _n_e = true;
        advance();
        Node* rNode = term();
        if (opToken._tokenType == t_plus)
            lNode = new Node(bo_plus, "\0" , lNode, rNode);
        if (opToken._tokenType == t_minus)
            lNode = new Node(bo_minus, "\0" , lNode, rNode);
    }
    return lNode;
}

Node* Parser::parse() {
    Node* node = expr();
    if (_i != (int)_tokens[0].size()) {
        node = expr();
    }
    return node;
}