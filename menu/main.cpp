#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>

#include "menumod/menu.hpp"
#include "menumod/Safe_Queue.hpp"
extern "C" {
	#include "oledmod/OLED_GUI.h"
}

std::atomic<bool> stop_thread = false;
Safe_Queue<int> Input_Queue;

void input_listener() {
	int time = 175;

	while(!stop_thread) {
		if(KEY_UP_RD == 0) {
			Input_Queue.enqueue(KEY_UP_ID);
        }
        if(KEY_DOWN_RD == 0) {
			Input_Queue.enqueue(KEY_DOWN_ID);
        }
        if(KEY_LEFT_RD == 0) {
			Input_Queue.enqueue(KEY_LEFT_ID);
        }
        if(KEY_RIGHT_RD == 0) {
			Input_Queue.enqueue(KEY_RIGHT_ID);
        }
        if(KEY_PRESS_RD == 0) {
			Input_Queue.enqueue(KEY_MID_ID);
        }
        if(KEY1_RD == 0) {
			Input_Queue.enqueue(KEY1_ID);
        }
        if(KEY2_RD == 0) {
			Input_Queue.enqueue(KEY2_ID);
        }
        if(KEY3_RD == 0) {
			Input_Queue.enqueue(KEY3_ID);
        }

		std::this_thread::sleep_for(std::chrono::milliseconds(time));
	}
}

int main(void)
{

	//1.System Initialization
    printf("*********Init System*********\r\n");
	if(DEV_ModuleInit())
		exit(0);
	
	//2.show
	printf("**********Init OLED**********\r\n");
	OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
	OLED_Init(OLED_ScanDir);
	GUI_LaunchScreen();

	//Start input thread
    printf("******Start Input Thread*****\r\n");
	std::thread input_thread(input_listener);

	Node* currentMenu = head;

    printf("********Starting Loop********\r\n");
	while (true) {
		if (!Input_Queue.empty()) {
			int choice = Input_Queue.dequeue();
			std::cout << "Menu: " << currentMenu->name() << " Input: " << choice << std::endl;
			currentMenu = currentMenu->input(choice);

			if (currentMenu == nullptr) {
				//System Exit
                printf("*********System Exi**********\r\n");
				GUI_ExitScreen();
				DEV_ModuleExit();
				stop_thread = true; //Close input thread loop
				input_thread.join(); //Close thread
				break;
			}
		}

		currentMenu->draw();
	}
    printf("********Closed Loop********\r\n");
}

//TODO: fins a way to make a node for application running
//TODO: Make a guitar note generator along with tempo