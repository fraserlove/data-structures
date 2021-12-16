/**
 * Priority Queue Data Structure Implementation using Binary Heaps
 * Author: Fraser Love, me@fraserlove.com
 * Created: 29/01/20
 * Latest Release: 01/02/20
 *
 * This file is a standalone console IO system for interfacing with the prioity
 * queue data structure declared in "PriorityQueue.h". The data struture itself
 * is functionally independent from this file which is only used for demonstration
 * and testing purposes. All bugs and general issues with this data structue are
 * welcomed and can be submitted at the repository page on Github.
 * 
 * All files included in this repository are protected by
 * the MIT Licence - Copyright (c) 2020 Fraser Love. See "PriorityQueue.h" or
 * "LICENCE.txt" at the root of this repository for licencing details.
 **/

#include <iostream>
#include <climits>

#include "PriorityQueue.h"

typedef int type;

void PrintHeader() {
	std::cout << " Priority Queue Data Structure Implementation using Binary Heaps" << std::endl;
	std::cout << " Author: Fraser Love, me@fraserlove.com" << std::endl;
	std::cout << " Latest Release: 01/02/20" << std::endl;
	std::cout << " MIT Licience - Copyright (c) 2020 Fraser Love" << std::endl;
	std::cout << std::endl << " Entered Test Console. Type \"list\" for commands or \"quit\" to exit" << std::endl << std::endl;
}

void PrintCommands() {
	std::cout << " All Commands (Must be entered lower case):" << std::endl << std::endl;
	std::cout << "     enqueue {value}" << std::endl << "     clear" << std::endl << "     show_debug" << std::endl;
	std::cout << "     length" << std::endl << "     find {index}" << std::endl << "     is_empty" << std::endl;
	std::cout << "     remove_value {value}" << std::endl << "     contains {value}" << std::endl << "     is_max" << std::endl << "     is_min" << std::endl;
	std::cout << "     valid_heap" << std::endl << "     dequeue" << std::endl << "     peek" << std::endl << std::endl;
}

void IOSystem(PQueue<type>* pqueue) {
	bool session = true;
	std::string cmd;
	type value;
	int idx;
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
			pqueue->Enqueue(value);
		}
		else if (cmd == "clear") {
			pqueue->Clear();
		}
		else if (cmd == "show_debug") {
			std::cout << " ";
			pqueue->ShowDebug();
		}
		else if (cmd == "length") {
			std::cout << " " << pqueue->Length() << std::endl;
		}
		else if (cmd == "find") {
			std::cin >> idx;
			std::cout << " " << pqueue->Find(idx) << std::endl;
		}
		else if (cmd == "is_empty") {
			std::cout << " " << pqueue->IsEmpty() << std::endl;
		}
		else if (cmd == "remove_value") {
			std::cin >> value;
			std::cout << " " << pqueue->RemoveValue(value) << std::endl;
		}
		else if (cmd == "contains") {
			std::cin >> value;
			std::cout << " " << pqueue->Contains(value) << std::endl;
		}
		else if (cmd == "is_max") {
			std::cout << " " << pqueue->IsMax() << std::endl;
		}
		else if (cmd == "is_min") {
			std::cout << " " << pqueue->IsMin() << std::endl;
		}
		else if (cmd == "valid_heap") {
			std::cout << " " << pqueue->ValidHeap() << std::endl;
		}
		else if (cmd == "dequeue") {
			std::cout << " " << pqueue->Dequeue() << std::endl;
		}
		else if (cmd == "peek") {
			std::cout << " " << pqueue->Peek() << std::endl;
		}
		else {
			std::cout << "ERROR: Invalid Command '" << cmd <<"' entered" << std::endl;
		}
		std::cin.ignore(INT_MAX, '\n');
	}
}

int main() {
	PQueue<type> pqueue;
	IOSystem(&pqueue);
}