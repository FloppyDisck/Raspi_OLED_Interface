#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

extern "C" {
	#include "oledmod/OLED_GUI.h"
}

#define WIDTH OLED_X_MAXPIXEL
#define HEIGHT OLED_Y_MAXPIXEL

class Node {
    public:
        Node(const char* name, Node* previous);
        virtual ~Node() {};
        virtual Node* input(int input) = 0;
        virtual void draw() = 0;
        void drawItem(bool selected, int x, int y, int xPadding,  int yPadding, sFONT* font, const char* text, int textLen=-1);
        const char* name();
        int nameLen();
        void setChildren(std::vector<Node*> children);
        void addChild(Node* child);
    protected:
        const char* name_;
        int nameLen_;
        Node* previous_;
        std::vector<Node*> children_ = {};
};

#endif