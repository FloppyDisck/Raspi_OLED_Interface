#include "statemod/ModProbeItem.hpp"

ModProbeItem::ModProbeItem(const char* name, Node *previous) :
StringItem(name, previous, {"OTG Off, Ethernet, K&M"}), moduleItems({"dwc2", "g_ether", "g_hid"}) {}

Node *ModProbeItem::input(int input) {
    //return StringItem::input(input);
    //Up arrow
    if (input==JOY_U) {
        state = max;
    }
        //Down arrow
    else if (input==JOY_D) {
        state = min;
    }
        //Left arrow
    else if (input==JOY_L) {
        //Goes left or negative
        state -= step;
        if (state < min) {
            state = min;
        }
    }
        //Right arrow
    else if (input==JOY_R) {
        //Goes right or positive
        state += step;
        if (state > max) {
            state = max;
        }
    }

    else if (input==JOY_M) {
        //Turn off all modules
        for (int i = moduleItems.size()-1; i >= 0; i--) {
            std::string cmd = stopMod + moduleItems[i];
            system(cmd.c_str());
        }

        //Turn on clicked module
        if (state > 0) {
            std::string cmd = startMod + moduleItems[0];
            system(cmd.c_str());
            cmd = startMod + moduleItems[state];
            system(cmd.c_str());
        }

        return previous_;
    }

    return this;
}

void ModProbeItem::draw() {
    StringItem::draw();
}
