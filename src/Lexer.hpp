#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "Token.hpp"
#include <vector>

class Lexer {
    public:
    std::vector<Token> _tokens;
    Lexer(std::string text);
    void make_tokens();
    void print_tokens();

    private:
    std::string _text;
    int _pos;
    char _current_char;
    void advance();
    Token make_number();
};

#endif