#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "ParsingNode.hpp"
#include "Number.hpp"

class Interpreter {
    public:
    Interpreter();
    Number* visit(Node* node);
    private:
    Number* visitNumberNode(Node* node);
    Number* visitBinaryOperationNode(Node* node);
    Number* visitUnaryOperationNode(Node* node);
};

#endif