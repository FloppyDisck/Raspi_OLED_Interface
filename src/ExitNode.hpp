#ifndef EXITNODE_HPP
#define EXITNODE_HPP
#include "Node.hpp"

class ExitNode : public Node {
    public:
        ExitNode(const char* name);
        Node* input(int input);
        void draw();
    private:
        bool exit_=false;

        //Formatting variables
        sFONT* font = &Font16;
		const int xPadding_ = 5; //Horizontal padding
		const int yPadding_ = 2; //The vertical padding

        //Frequently used for drawing
        const int yesSize_ = font->Width * 3;
        const int noSize_ = font->Width * 2;

        const int titleYLoc_ = (HEIGHT/4) - (font->Height/2);
        const int titleXLoc_ = (WIDTH/2) - ((font->Width * nameLen_)/2);

        const int answerYLoc_ = (HEIGHT/4)*3 - (font->Height/2) - yPadding_;

        const int yesXLoc_ = (WIDTH/4) - (yesSize_/2) - xPadding_;
        const int noXLoc_ = (WIDTH/4)*3 - (noSize_/2) - xPadding_;
};

#endif