#include "statemod/IntegerItem.hpp"

IntegerItem::IntegerItem(const char *name, Node *previous, int minValue, int maxValue, int stepQnty, int initState)
        : StateItem(name, previous, minValue, maxValue, stepQnty, initState) {}

Node *IntegerItem::input(int input) {
    return StateItem::input(input);
}

void IntegerItem::draw() {
    StateItem::draw();
}

int IntegerItem::update(bool dir) {
    return StateItem::update(dir);
}

