#include "statemod/IntegerItem.hpp"

IntegerItem::IntegerItem(const char *name, Node *previous, int minValue, int maxValue, int stepQnty, int initState)
        : StateItem(name, previous, minValue, maxValue, stepQnty, initState) {}
