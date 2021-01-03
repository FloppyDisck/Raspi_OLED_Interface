#ifndef MODPROBEITEM_HPP
#define MODPROBEITEM_HPP
#include "statemod/StringItem.hpp"

class ModProbeItem : public StringItem {
public:
    ModProbeItem(const char* name, Node* previous);
    Node* input(int input) override;
    void draw() override;
protected:
    std::vector<std::string> moduleItems;
    std::string startMod = "sudo modprobe ";
    std::string stopMod = "sudo modprobe -r ";
};

#endif