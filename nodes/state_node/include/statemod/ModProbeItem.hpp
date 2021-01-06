#ifndef MODPROBEITEM_HPP
#define MODPROBEITEM_HPP

#include <fstream>
#include "statemod/StringItem.hpp"

class ModProbeItem : public StringItem {
public:
    ModProbeItem(const char* name, Node* previous);
    Node* input(int input) override;
    void draw() override;
    std::ofstream HID_OUT;
protected:
    std::vector<std::string> moduleItems;
    std::string startMod = "sudo modprobe -a ";
    std::string stopMod = "sudo modprobe -a -r ";
};

#endif