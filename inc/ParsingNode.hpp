#ifndef PARSINGNODE_HPP
#define PARSINGNODE_HPP

#include <string>

enum NodeType {
    unidifined, bo_plus, bo_minus, bo_mul, bo_div, n_float, n_int, uo_neg
};

class Node {
    public:
    Node(NodeType type, std::string value, Node *lNode, Node *rNode, Position* pos);
    Node(NodeType type, std::string value, Position* pos);
    Node(NodeType type, Node *lNode, Position* pos);
    Node();
    std::string toString();
    NodeType _type;
    Node* _lNode;
    Node* _rNode;
    std::string _value;
    Position* _pos;
    NodeType getNodeType();
    private:
};

#endif