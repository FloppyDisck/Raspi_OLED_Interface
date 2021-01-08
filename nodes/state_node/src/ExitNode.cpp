#include "statemod/ExitNode.hpp"

// We place an empty function since we wont use it anyways
ExitNode::ExitNode(const char *name) :
BinaryItem(name, nullptr, std::function<void(bool)>([](bool a) -> void {})) {}

Node *ExitNode::input(int input) {
    //Left arrow
    if (input==JOY_L) {
        state = 1;
    }
    //Right arrow
    else if (input==JOY_R) {
        state = 0;
    }

    else if (input==JOY_M) {
        if (state == 1) {
            return nullptr;
        } else {
            return children_[0];
        }
    }

    return this;
}

void ExitNode::draw() {
    BinaryItem::draw();
}
