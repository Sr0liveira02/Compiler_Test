#ifndef PARSINGNODE_HPP
#define PARSINGNODE_HPP

#include <string>

enum NodeType {
    unidifined, bo_plus, bo_minus, bo_mul, bo_div, n_float, n_int 
};

class Node {
    public:
    Node(NodeType type, std::string value, Node *lNode, Node *rNode);
    Node(NodeType type, std::string value);
    Node();
    std::string toString();
    NodeType _type;
    Node* _lNode;
    Node* _rNode;
    std::string _value;
    private:
};

#endif