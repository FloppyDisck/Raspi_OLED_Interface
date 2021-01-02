#include "nodemod/BinaryOptionNode.hpp"

BinaryOptionNode::BinaryOptionNode(const char* name, Node* previous, bool showState, bool initState) :
Node(name, previous), verbose(showState), state(initState) {
    baseName = name_;
    if (verbose) {
        this->updateName();
    }
}

void BinaryOptionNode::setState(bool newState) {
    state = newState;
    if (verbose) {
        this->updateName();
        this->run();
    }
}

void BinaryOptionNode::run() {

}

void BinaryOptionNode::draw() {

}

Node* BinaryOptionNode::input(int input) {
    return previous_;
}

void BinaryOptionNode::updateName() {
    std::string suffix;
    if (state) {
        suffix = " : ON";
    } else {
        suffix = " : OFF";
    }

    std::string newName = (baseName+" : ON");
    name_ = newName.c_str();
    nameLen_ = newName.size();
}