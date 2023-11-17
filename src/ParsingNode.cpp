#include "../inc/shell.hpp"

Node::Node(NodeType type, std::string value, Node *lNode, Node *rNode, Position* pos) {
    _type = type;
    _pos = pos;
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
        case uo_neg:
            _lNode = lNode;
            _value = "\0";
            _rNode = NULL;
            break;
        case unidifined:
            std::cout << "Error!\n";
            break;
    }
}

Node::Node(NodeType type, std::string value, Position* pos) {
    _type = type;
    _pos = pos;
    _value = value;
    _lNode = NULL;
    _rNode = NULL;
}

Node::Node(NodeType type, Node* lNode, Position* pos) {
    _type = type;
    _pos = pos;
    _value = "\0";
    _lNode = lNode;
    _rNode = NULL;
}

Node::Node() {
    _type = unidifined;
    _value = "Error!\n";
    _lNode = NULL;
    _rNode = NULL;
}

NodeType Node::getNodeType() {
    return _type;
}

std::string Node::toString() {
    switch(_type) {
        case bo_plus:
            return "[" + _lNode->toString() + " + " + _rNode->toString() + "]";
        case bo_minus:
            return "[" + _lNode->toString() + " - " + _rNode->toString() + "]";
        case bo_mul:
            return "[" + _lNode->toString() + " * " + _rNode->toString() + "]";
        case bo_div:
            return "[" + _lNode->toString() + " / " + _rNode->toString() + "]";
        case n_float:
        case n_int:
            return _value;
        case uo_neg:
            return "-(" + _lNode->toString() + ")";
        case unidifined:
            return "Error!\n";
    }   
    return "Error!\n";
}
