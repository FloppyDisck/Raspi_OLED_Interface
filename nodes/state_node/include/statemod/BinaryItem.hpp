#ifndef BINARYITEM_HPP
#define BINARYITEM_HPP

#include <utility>
#include <functional>
#include "statemod/StateItem.hpp"

class BinaryItem : public IntegerItem {
public:
    BinaryItem(const char* name, Node* previous, std::function<void(bool)> function);
    Node* input(int input) override;
    void draw() override;
protected:
    std::function<void(bool)> f;
};

#endif
