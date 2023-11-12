#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "Token.hpp"
#include <vector>

class Position {
    public:
    Position(int i, int ln, int col, std::string fileName, std::string fileText);
    Position();
    int _i;
    int _ln;
    int _col;
    std::string _fileName;
    std::string _fileText;
    void advance(char currentChar);
    Position copy();
    private:
};

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