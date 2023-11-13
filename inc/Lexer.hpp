#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "Token.hpp"
#include "Position.hpp"
#include <vector>

class Lexer {
    public:
    std::vector<Token> _tokens;
    Lexer(std::string fileName, std::string fileText);
    void make_tokens();
    void print_tokens();

    private:
    std::string _fileName;
    std::string _text;
    Position _pos;
    char _current_char;
    void advance();
    Token make_number();
};

#endif