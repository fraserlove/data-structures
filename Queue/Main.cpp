/**
 * Queue Data Structure Implementation using Singly Linked Lists
 * Author: Fraser Love, me@fraserlove.com
 * Created: 28/01/20
 * Latest Release: 02/02/20
 *
 * This file is a standalone console IO system for interfacing with the queue
 * data structure declared in "Queue.h". The data struture itself is functionally
 * independent from this file which is only used for demonstration and testing
 * purposes. All bugs and general issues with this data structue are welcomed
 * and can be submitted at the repository page on Github.
 *
 * All files included in this repository are protected by
 * the MIT Licence - Copyright (c) 2020 Fraser Love. See "Queue.h" or
 * "LICENCE.txt" at the root of this repository for licencing details.
 **/

#include <iostream>
#include <climits>

#include "Queue.h"

typedef int type;

void PrintHeader() {
    std::cout << " Queue Data Structure Implementation using Singly Linked Lists" << std::endl;
    std::cout << " Author: Fraser Love, me@fraserlove.com" << std::endl;
    std::cout << " Latest Release: 02/02/20" << std::endl;
    std::cout << " MIT Licience - Copyright (c) 2020 Fraser Love" << std::endl;
    std::cout << std::endl << " Entered Test Console. Type \"list\" for commands or \"quit\" to exit" << std::endl << std::endl;
}

void PrintCommands() {
    std::cout << " All Commands (Must be entered lower case):" << std::endl << std::endl;
    std::cout << "     enqueue {value}" << std::endl << "     clear" << std::endl << "     show" << std::endl;
    std::cout << "     length" << std::endl << "     is_empty" << std::endl << "     dequeue" << std::endl << "     peek" << std::endl << std::endl;
}

void IOSystem(Queue<type>* queue) {
	bool session = true;
	std::string cmd;
	type value;
	PrintHeader();
	while (session) {
		std::cout << " > ";
		std::cin >> cmd;
		if (cmd == "quit") {
			session = false;
		}
		else if (cmd == "list") {
			PrintCommands();
		}
		else if (cmd == "enqueue") {
			std::cin >> value;
			queue->Enqueue(value);
		}
		else if (cmd == "clear") {
			queue->Clear();
		}
		else if (cmd == "show") {
			std::cout << " ";
			queue->Show();
		}
		else if (cmd == "length") {
			std::cout << " " << queue->Length() << std::endl;
		}
		else if (cmd == "is_empty") {
			std::cout << " " << queue->IsEmpty() << std::endl;
		}
		else if (cmd == "dequeue") {
			std::cout << " " << queue->Dequeue() << std::endl;
		}
		else if (cmd == "peek") {
			std::cout << " " << queue->Peek() << std::endl;
		}
		else {
			std::cout << "ERROR: Invalid Command '" << cmd << "' entered" << std::endl;
		}
		std::cin.ignore(INT_MAX, '\n');
	}
}

int main() {
	Queue<int> queue;
	IOSystem(&queue);
}