#ifndef GENERATEDMENU_HPP
#define GENERATEDMENU_HPP
#include "nodemod/ExitNode.hpp"
#include "nodemod/MenuNode.hpp"
ExitNode t0 = ExitNode("Exit?");
MenuNode t1 = MenuNode("Head", &t0);
MenuNode t2 = MenuNode("Item 1", &t1);
MenuNode t3 = MenuNode("Other item 1", &t2);
MenuNode t4 = MenuNode("Other item 1", &t2);
MenuNode t5 = MenuNode("Other item 1", &t2);
MenuNode t6 = MenuNode("Item 2", &t1);
MenuNode t7 = MenuNode("Item 3", &t1);
MenuNode t8 = MenuNode("Item 4", &t1);
MenuNode t9 = MenuNode("Item 5", &t1);
MenuNode t10 = MenuNode("Item 6", &t1);
Node* head = &t1;
#endif