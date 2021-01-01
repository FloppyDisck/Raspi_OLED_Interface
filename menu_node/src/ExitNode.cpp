#include "nodemod/ExitNode.hpp"

ExitNode::ExitNode(const char* name):Node(name, nullptr) {}

Node* ExitNode::input(int input) {
	//Left arrow or right arrow
	if (input==2 || input==3) {
		exit_ = !exit_;
	}
	//Middle click
	else if (input==4 && !exit_) {
		return children_[0];
	}

    else if (input==4 && exit_) {
		return previous_;
	}

	return this;
}

void ExitNode::draw() {
    //TODO: Fix formatting issues

    GUI_DisString_EN(titleXLoc_, titleYLoc_, name_, font, FONT_BACKGROUND, FONT_FOREGROUND);

    drawItem(exit_, yesXLoc_, answerYLoc_, xPadding_, yPadding_, font, "YES", yesSize_);
    drawItem(!exit_, noXLoc_, answerYLoc_, xPadding_, yPadding_, font, "NO", noSize_);

    OLED_Display();		
	OLED_Clear(0x00);
}