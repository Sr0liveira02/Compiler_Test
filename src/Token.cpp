#include "../inc/shell.hpp"

Token::Token(TokenType tokenType, std::string value, Position* pos) {
    _tokenType = tokenType;
    _value = value;
    _pos = pos;
}

Token::Token(TokenType tokenType, char value, Position* pos) {
    _tokenType = tokenType;
    _value = value;
    _pos = pos;
}

Token::Token() {
    _tokenType = undifined;
    _value = "-1";
}

std::string Token::toString() {
    std::string type;
    switch(_tokenType) {
        case t_int:
            type = "t_int";
            break;
        case t_float:
            type = "t_float";
            break;
        case t_plus:
            type = "t_plus";
            break;
        case t_minus:
            type = "t_minus";
            break;
        case t_mul:
            type = "t_mul";
            break;
        case t_div:
            type = "t_div";
            break;
        case t_lparen:
            type = "t_lparen";
            break;
        case t_rparen:
            type = "t_rparen";
            break;
        case unidifined:
            type = "Erro!";
            break;
    }
    if (this->_value[0] != '\0')
        return "[" + type + ":" + _value + "]";
    else 
        return "[" + type + "]";
}