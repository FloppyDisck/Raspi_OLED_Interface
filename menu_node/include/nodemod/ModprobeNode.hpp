#ifndef MODPROBENODE_HPP
#define MODPROBENODE_HPP
#include "nodemod/MenuNode.hpp"
#include "nodemod/BinaryOptionNode.hpp"

//TODO: another node that just keeps program information /n
// for example g_ether_active = True when g_ether is activated

class ModprobeOption : public BinaryOptionNode {
    public:
        ModprobeOption(const char* name, Node* previous, std::string modName);
        void run() override;
    private:
        const char* turnOff;
        const char* turnOn;
};

class ModprobeNode : public MenuNode {
    public:
        ModprobeNode(const char* name, Node* previous);
        void draw() virtual;
    protected:
        Node* selectItem(int option) override;
        std::vector<ModprobeOption> options;
};

#endif