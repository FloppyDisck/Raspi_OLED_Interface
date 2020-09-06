#include "Node.hpp"

Node::Node(const char* name, Node* previous) {
    name_ = name;
	nameLen_ = std::string(name_).size();
	previous_ = previous;

	if (previous != nullptr) {
		previous->addChild(this);
	}
}

void Node::drawItem(bool selected, int x, int y, int xPadding,  int yPadding, sFONT* font, const char* text, int textLen) {
    if (selected) {
        if (textLen==-1)
            textLen = std::string(text).size();

        int textSize = textLen * font->Width;

        int x2 = x + (xPadding*2) + textSize;
        int y2 = y + (yPadding*2) + font->Height - 1;

        int xl = (x2 - x - 2)/3;

        //Left Bracket
        GUI_DrawLine(x, y, x, y2, WHITE, LINE_SOLID, DOT_PIXEL_DFT);
        GUI_DrawLine(x, y, x + xl, y, WHITE, LINE_SOLID, DOT_PIXEL_DFT);
        GUI_DrawLine(x, y2, x + xl, y2, WHITE, LINE_SOLID, DOT_PIXEL_DFT);

        //Right Bracket
        GUI_DrawLine(x2, y, x2, y2, WHITE, LINE_SOLID, DOT_PIXEL_DFT);
        GUI_DrawLine(x2, y, x2 - xl, y, WHITE, LINE_SOLID, DOT_PIXEL_DFT);
        GUI_DrawLine(x2, y2, x2 - xl, y2, WHITE, LINE_SOLID, DOT_PIXEL_DFT);
    }

    //Text
    GUI_DisString_EN(x + xPadding+1, y + yPadding+1, text, font, FONT_BACKGROUND, FONT_FOREGROUND);
}

const char* Node::name() {
    return name_;
}

int Node::nameLen() {
    return nameLen_;
}

void Node::setChildren(std::vector<Node*> children) {
    children_ = children;
}

void Node::addChild(Node* child) {
     children_.push_back(child);
}