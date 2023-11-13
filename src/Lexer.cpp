#include "../inc/shell.hpp"

Position::Position(int i, int ln, int col, std::string fileName, std::string fileText) {
    _i = i;
    _ln = ln;
    _col = col;
    _fileName = fileName;
    _fileText = fileText;
}

Position::Position() {
    _i = -1;
    _ln = 0;
    _col = -1;
}

void Position::advance(char current_char) {
    _i++;
    _col++;

    if (current_char == '\n') {
        _col = 0;
        _ln++;
    }
}

Position Position::copy() {
    return Position(_i, _ln, _col, _fileName, _fileText);
}

Lexer::Lexer(std::string fileName, std::string fileText) {
    _text = fileText;
    _fileName = fileName;
    _pos = Position(-1, 0, -1, fileName, fileText);
    advance();
}

void Lexer::advance() {
    _pos.advance(_current_char);
    if (_pos._i < (int)_text.size())
        _current_char = _text[_pos._i];
    else
        _current_char = '\0';
}

Token Lexer::make_number() {
    std::string number;
    bool dot = false;

    while (_current_char != '\n' &&
         ((('0' <= _current_char && _current_char <= '9') ||
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
                if('0' <= _current_char && _current_char <= '9') {
                    _tokens.push_back(make_number());
                    continue;;
                }
                else {
                    std::cerr << "Illegal Character used: '" << _current_char << "'\n";
                    std::cerr << "In File: '" << _fileName << "', line " << (_pos._ln + 1) << "\n";
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