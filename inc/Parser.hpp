#ifndef PARSER_HPP
#define PARSER_HPP

#include "Lexer.hpp"
#include <vector>
#include "Token.hpp"
#include "ParsingNode.hpp"


class Parser {
    public:
    Parser(std::vector<Token>* tokens);
    std::vector<Token>* _tokens;
    int _i;
    Token _currentToken;
    void advance();
    void print_tree();
    Node* parse();
    private:
    Node* factor();
    Node* term();
    Node* expr();
    bool _n_e; // false means last was a number, true means last was a expression
};

#endif