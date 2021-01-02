#include "nodemod/ModprobeNode.hpp"

ModprobeOption::ModprobeOption(const char* name, Node* previous, std::string modName) : BinaryOptionNode(name, previous) {
    turnOff = ("sudo modprobe -r " + modName).c_str();
    turnOn = ("sudo modprobe " + modName).c_str();
}

void ModprobeOption::run() {
    if (state) {
        system(turnOn);
    } else {
        system(turnOff);
    }
}


ModprobeNode::ModprobeNode(const char* name, Node* previous):MenuNode(name, previous) {
    options.push_back(ModprobeOption("DWC2", this, "dwc2"));
    options.push_back(ModprobeOption("OTG Ethernet", this, "g_ether"));
    options.push_back(ModprobeOption("OTG HID", this, " "));
}

Node* ModprobeNode::selectItem(int option) {
    for (int i = 1; i < options.size(); i++) {
        if (i != option) {
            options[i].setState(false);
        }
    }
    options[option].setState(true);
    return this;
}

void ModprobeNode::draw() {
    int lim = (options.size() < 4) ? options.size() : 4; //Prevent overloading when handling small items

	//Grab the next 4 items starting with the current _scope
	for (int i=0; i < lim; i++) {

		int item = i + scope_;

		//Top and bottom coordinates for the current box
		int itemTop = (i*itemSize_) + 1;

		drawItem((item == selected_), 1, itemTop, xPadding_, 
        yPadding_, font, options[item].name(), options[item].nameLen());
	}
	OLED_Display();
	OLED_Clear(0x00);
}