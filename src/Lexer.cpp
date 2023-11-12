#include "../inc/shell.hpp"

Lexer::Lexer(std::string text) {
    _text = text;
    _pos = -1;
    advance();
}

void Lexer::advance() {
    _pos = _pos + 1;
    if (_pos < (int)_text.size())
        _current_char = _text[_pos];
    else
        _current_char = '\0';
}

Token Lexer::make_number() {
    std::string number;
    bool dot = false;

    while (_current_char != '\n' &&
         ((('0' < _current_char && _current_char < '9') ||
         _current_char == '.'))) {

        if (_current_char == '.')
            dot = true;
        number = number + _current_char;
        advance();
    }
    if (!dot) {
        return Token(t_int, number);
    }
    else {
        return Token(t_float, number);
    }
}

void Lexer::make_tokens() {
    while (_current_char != '\0') {
        switch(_current_char) {
            case ' ':
            case '\t':
            case '\n':
                advance();
                break;
            case '+':
                _tokens.push_back(Token(t_plus, '\0'));
                advance();
                break;
            case '-':
                _tokens.push_back(Token(t_minus, '\0'));
                advance();
                break;
            case '*':
                _tokens.push_back(Token(t_mul, '\0'));
                advance();
                break;
            case '/':
                _tokens.push_back(Token(t_div, '\0'));
                advance();
                break;
            case '(':
                _tokens.push_back(Token(t_lparen, '\0'));
                advance();
                break;
            case ')':
                _tokens.push_back(Token(t_rparen, '\0'));
                advance();
                break;
            default:
                if('0' < _current_char && _current_char < '9') {
                    _tokens.push_back(make_number());
                    continue;;
                }
                else {
                    std::cerr << "Illegal Character used: '" << _current_char << "'\n";
                    _tokens.clear();
                    return;
                    // add something to manage this
                }
        }
    }
}

void Lexer::print_tokens() {
    int max = _tokens.size();
    for (int i = 0; i < max; i++) {
        std::cout << _tokens[i].toString() << "\n";
    }
}