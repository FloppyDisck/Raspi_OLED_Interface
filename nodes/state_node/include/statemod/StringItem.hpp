#ifndef STRINGITEM_HPP
#define STRINGITEM_HPP
#include "statemod/StateItem.hpp"

class StringItem : public IntegerItem {
public:
    StringItem(const char* name, Node* previous, const std::vector<const char*>&items);
    Node* input(int input) override;
    void draw() override;
    const char* getStateLiteral();
protected:
    std::vector<const char*>literalItems;
};

#endif