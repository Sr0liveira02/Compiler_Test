#include "../inc/shell.hpp"

Node::Node(NodeType type, std::string value, Node *lNode, Node *rNode) {
    _type = type;
    switch(type) {
        case bo_plus:
        case bo_minus:
        case bo_mul:
        case bo_div:
            _lNode = lNode;
            _rNode = rNode;
            _value = "\0";
            break;
        case n_float:
        case n_int:
            _lNode = NULL;
            _rNode = NULL;
            _value = value;
            break;
        case unidifined:
            std::cout << "Error!\n";
            break;
    }
}

Node::Node(NodeType type, std::string value) {
    _type = type;
    _value = value;
}

Node::Node() {
    _type = unidifined;
    _value = "Error!\n";
}

std::string Node::toString() {
    switch(_type) {
        case bo_plus:
            return "(" + _lNode->toString() + " + " + _rNode->toString() + ")";
        case bo_minus:
            return "(" + _lNode->toString() + " - " + _rNode->toString() + ")";
        case bo_mul:
            return "(" + _lNode->toString() + " * " + _rNode->toString() + ")";
        case bo_div:
            return "(" + _lNode->toString() + " / " + _rNode->toString() + ")";
        case n_float:
        case n_int:
            return _value;
        case unidifined:
            return "Error!\n";
    }   
    return "Error!\n";
}
