#ifndef HIDSCRIPTNODE_HPP
#define HIDSCRIPTNODE_HPP
#include "nodemod/Node.hpp"
#include "HID_Keys.hpp"
#include <fstream>
#include <chrono>
#include <thread>

char* char2HID(char c);

//TODO: filemanager just generated menu_nodes
//TODO: override file manager
//TODO: fake files with passwdd
class HIDScriptNode : public Node {
public:
    HIDScriptNode(const char* name, Node* previous);
    Node* input(int input) override;
    void draw() override;

protected:
};

#endif



