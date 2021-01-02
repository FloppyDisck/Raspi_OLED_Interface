#ifndef BINARYOPTIONNODE_HPP
#define BINARYOPTIONNODE_HPP
#include "nodemod/Node.hpp"

class BinaryOptionNode : public Node {
    public:
        BinaryOptionNode(const char* name, Node* previous, bool showState, bool initState);
        void setState(bool newState);

        void updateName();
        Node* input(int input) override;
        void draw() override;
        virtual void run();
        bool state, verbose;
    protected:
        std::string baseName;
};
#endif