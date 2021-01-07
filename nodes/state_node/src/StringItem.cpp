#include "statemod/StringItem.hpp"

StringItem::StringItem(const char *name, Node *previous, const std::vector<const char *>& items) :
IntegerItem(name, previous, 0, items.size()-1, 1, 0), literalItems(items) {}

Node *StringItem::input(int input) {
    return StateItem::input(input);
}

void StringItem::draw() {
    int mid = OLED_X_MAXPIXEL/2 - (nameLen_ * font->Width)/2;
    drawItem(false, mid, 1, 0, 0, font, name_, nameLen_);


    std::string valStr = std::string(literalItems[IntegerItem::getState()]);
    const char* valC = valStr.c_str();
    int valN = valStr.size();
    mid = OLED_X_MAXPIXEL/2 - (valN * font->Width)/2;
    drawItem(false, mid, 1 + (2*itemSize_), 0, 0, font, valC, valN);
    OLED_Display();
    OLED_Clear(0x00);
}

const char *StringItem::getStateLiteral() {
    return literalItems[IntegerItem::getState()];
}
