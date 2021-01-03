#ifndef INTEGERITEM_HPP
#define INTEGERITEM_HPP
#include "statemod/StateItem.hpp"

class IntegerItem : public StateItem<int> {
public:
    IntegerItem(const char* name, Node* previous, int minValue, int maxValue, int stepQnty, int initState);
};

#endif