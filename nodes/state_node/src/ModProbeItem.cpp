#include "statemod/ModProbeItem.hpp"

// Some OTG setup info
// https://linux-sunxi.org/USB_Gadget

ModProbeItem::ModProbeItem(const char* name, Node *previous) :
StringItem(name, previous, {"OTG Off", "Ethernet", "K&M"}) {}

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
        system("sudo modprobe -a -r g_ether libcomposite dwc2");

        //Turn on Ethernet
        if (state == 1) {
            system("sudo modprobe -a dwc2 g_ether");
        }

        // Turn on HID
        if (state == 2) {
            system("sudo modprobe -a dwc2 libcomposite");
            system("sudo bash /usr/local/bin/OTG_HID_INIT.sh");
            HID_OUT.open("/dev/hidg0");
        }

        return previous_;
    }

    return this;
}

void ModProbeItem::draw() {
    StringItem::draw();
}
