#include "shell.hpp"

Token::Token(TokenType tokenType, std::string value) {
    _tokenType = tokenType;
    _value = value;
}

Token::Token(TokenType tokenType, char value) {
    _tokenType = tokenType;
    _value = value;
}

void Token::toString() {
    std::string type;
    switch(_tokenType) {
        case 0:
            type = "t_int";
            break;
        case 1:
            type = "t_float";
            break;
        case 2:
            type = "t_plus";
            break;
        case 3:
            type = "t_minus";
            break;
        case 4:
            type = "t_mul";
            break;
        case 5:
            type = "t_div";
            break;
        case 6:
            type = "t_lparen";
            break;
        case 7:
            type = "t_rparen";
            break;
    }
    if (this->_value[0] != '\0')
        std::cout << "[" << type << ":" << _value << "]";
    else 
        std::cout << "[" << type << "]";
}