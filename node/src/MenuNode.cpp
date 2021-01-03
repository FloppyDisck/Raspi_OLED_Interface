#include "nodemod/MenuNode.hpp"

MenuNode::MenuNode(const char* name, Node* previous):Node(name, previous) {}

Node* MenuNode::input(int input) {
	//Up arrow
	if (input==JOY_U) {
		if (selected_ == 0) { 
			//Set view to bottom
			selected_ = children_.size() -1;

			//Set scope to bottom
			if (children_.size() > 4)
				scope_ = children_.size() - 4;
		}
		else { 
			selected_--;
			if (selected_ < scope_)
				scope_--;

		}
	}
	//Down arrow
	else if (input==JOY_D) {
		if (selected_ == children_.size() -1) { 
			selected_ = 0;
			scope_ = 0;
		}
		else { 
			selected_++;
			if (selected_ > scope_+3)
				scope_++;
		}
	}
	//Left arrow
	else if (input==JOY_L) {
		return previous_;
	}
	//Right arrow or middle click
	else if (input==JOY_R || input==JOY_M) {
		//return children_[selected_];
		return selectItem(selected_);
	}

	return this;
}

void MenuNode::draw() {
	int lim = (children_.size() < 4) ? children_.size() : 4; //Prevent overloading when handling small items

	//Grab the next 4 items starting with the current _scope
	for (int i=0; i < lim; i++) {

		int item = i + scope_;

		//Top and bottom coordinates for the current box
		int itemTop = (i*itemSize_) + 1;

		drawItem((item == selected_), 1, itemTop, xPadding_, yPadding_, font, children_[item]->name(), children_[item]->nameLen());
	}
	OLED_Display();
	OLED_Clear(0x00);
}

Node* MenuNode::selectItem(int option) {
	return children_[option];
}