#ifndef HIDSCRIPTNODE_HPP
#define HIDSCRIPTNODE_HPP
#include "nodemod/Node.hpp"
#include "statemod/ModProbeItem.hpp"
#include "HID_Keys.hpp"

std::string HID_EMPTY = "\\0";
std::string HID_PACKET_PREFIX = "\\x";
std::string HID_PACKET_TRAIL = "\\0\\0\\0\\0\\0";
std::string HID_EMPTY_PACKET = "\\0\\0\\0\\0\\0\\0\\0\\0";

std::string char2HID(char c);
template <typename I> std::string n2hexstr(I w);

//TODO: filemanager just generated menu_nodes
//TODO: override file manager
//TODO: fake files with passwdd
class HIDScriptNode : public Node {
public:
    HIDScriptNode(const char* name, Node* previous, ModProbeItem* modprobe);
    Node* input(int input) override;
    void draw() override;

protected:
    ModProbeItem* modprobe;
};

#endif