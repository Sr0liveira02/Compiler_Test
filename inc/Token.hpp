#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum TokenType {
    undifined, t_int, t_float, t_plus, t_minus, t_mul, t_div, t_lparen, t_rparen
};

class Token {
    public:
    Token(TokenType _tokenType, std::string value);
    Token(TokenType _tokenType, char value);
    Token();
    TokenType _tokenType;
    std::string _value;

    std::string toString();
    private:
};

#endif