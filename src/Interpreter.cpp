#include "../inc/shell.hpp"

Interpreter::Interpreter() {

}

Number* Interpreter::visitNumberNode(Node* node) {
    float value = std::stof(node->_value);
    return new Number(value, node->_pos);
}

Number* Interpreter::visitBinaryOperationNode(Node* node) {
    Number* left = visit(node->_lNode);
    Number* right = visit(node->_rNode);
    switch(node->_type) {
        case bo_plus:
            return left->add(right);
        case bo_minus:
            return left->sub(right);
        case bo_mul:
            return left->mul(right);
        case bo_div:
            return left->div(right, node->_pos);
        default:
            std::cerr << "Erro nas operaçoes do interpreter!\n";
            exit(1);
    }
    return new Number();
}

Number* Interpreter::visitUnaryOperationNode(Node* node) {
    Number* number = visit(node->_lNode);
    switch(node->_type) {
        case uo_neg:
            return number->mul(new Number(-1, node->_pos));
        default:
            std::cerr << "Erro nas operaçoes do interpreter!\n";
            exit(1);
    }
    return new Number();
}

Number* Interpreter::visit(Node* node) {
    NodeType type = node->getNodeType();
    switch(type) {
        case bo_plus:
        case bo_minus:
        case bo_mul:
        case bo_div:
            return visitBinaryOperationNode(node);
        case n_float:
        case n_int:
            return visitNumberNode(node);
        case uo_neg:
            return visitUnaryOperationNode(node);
        case unidifined:
            std::cerr << "Fuck Interpreter Node Type\n";
            exit(1);
            break;
    }
    return new Number();
}