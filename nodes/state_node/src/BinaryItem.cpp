#include "statemod/BinaryItem.hpp"

#include <utility>

BinaryItem::BinaryItem(const char *name, Node *previous, std::function<void(bool)> function) :
IntegerItem(name, previous, 0, 1, 1, 0), f(std::move(function)) { }

Node *BinaryItem::input(int input) {
        //Left arrow
     if (input==JOY_L) {
        state = 1;
    }
        //Right arrow
    else if (input==JOY_R) {
        state = 0;
    }

    else if (input==JOY_M) {
        f(state);
        return previous_;
    }

    return this;
}

void BinaryItem::draw() {
    int mid = OLED_X_MAXPIXEL/2 - (nameLen_ * font->Width)/2;
    drawItem(false, mid, 1, 0, 0, font, name_, nameLen_);

    const char* yes = "Yes";
    int yesS = 3;
    mid = OLED_X_MAXPIXEL/4 - (yesS * font->Width)/2 - xPadding_;
    drawItem(state==1, mid, 1 + (2*itemSize_), xPadding_, yPadding_, font, yes, yesS);

    const char* no = "No";
    int noS = 2;
    mid = (OLED_X_MAXPIXEL/4)*3 - (noS * font->Width)/2 - xPadding_;
    drawItem(state==0, mid, 1 + (2*itemSize_), xPadding_, yPadding_, font, no, noS);

    OLED_Display();
    OLED_Clear(0x00);
}
