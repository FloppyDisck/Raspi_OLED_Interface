#ifndef EXITNODE_HPP
#define EXITNODE_HPP

#include "statemod/BinaryItem.hpp"

class ExitNode : public BinaryItem {
public:
    ExitNode(const char* name);
    Node* input(int input) override;
    void draw() override;
};

#endif