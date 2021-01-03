#ifndef MENUNODE_HPP
#define MENUNODE_HPP
#include "nodemod/Node.hpp"

//TODO: make text formating font dependent

//TODO: add non selectable options (like a title)

//Menu node is used to display a series of options

class MenuNode : public Node {
	public:
		MenuNode(const char* name, Node* previous);
		Node* input(int input);
		void draw();
	protected:
		Node* selectItem(int option);

		int selected_=0;
		int scope_=0;

		//Drawing variables
		sFONT* font = &Font12;
		const int xPadding_ = 5; //Horizontal padding
		const int yPadding_ = 2; //The vertical padding

		const int itemSize_ = (yPadding_ * 2) + font->Height; //Horizontal size of each item
};
#endif