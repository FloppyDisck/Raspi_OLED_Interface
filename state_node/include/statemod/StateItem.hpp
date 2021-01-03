#ifndef STATEITEM_HPP
#define STATEITEM_HPP
#include "nodemod/Node.hpp"

template <typename T>
class StateItem : public Node {
public:
    StateItem(const char* name, Node* previous, T minValue, T maxValue, T stepQnty, T initState);
    Node* input(int input) override;
    void draw() override;
    T getState();

protected:
    T min, max, step, state;

    //Drawing variables
    sFONT* font = &Font12;
    const int xPadding_ = 5; //Horizontal padding
    const int yPadding_ = 2; //The vertical padding

    const int itemSize_ = (yPadding_ * 2) + font->Height; //Horizontal size of each item

};

using IntegerItem = StateItem<int>;
using FloatItem = StateItem<float>;
using DoubleItem = StateItem<double>;

#endif