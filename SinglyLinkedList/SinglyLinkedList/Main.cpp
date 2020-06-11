/**
 * Singly Linked List Data Structure Implementation
 * Author: Fraser Love, me@fraserlove.com
 * Created: 17/01/20
 * Latest Release: 01/02/20
 *
 * This file is a standalone console IO system for interfacing with the singly
 * linked list data structure declared in "SinglyLinkedList.h". The data struture
 * itself is functionally independent from this file which is only used for
 * demonstration and testing purposes. All bugs and general issues with this data
 * structure are welcomed and can be submitted at the repository page on Github.
 *
 * All files included in this repository are protected by
 * the MIT Licence - Copyright (c) 2020 Fraser Love. See "SinglyLinkedList.h" or
 * "LICENCE.txt" at the root of this repository for licencing details.
 **/

#include <iostream>
#include <climits>

#include "SinglyLinkedList.h"

typedef int type;

void PrintHeader() {
    std::cout << " Singly Linked List Data Implementation" << std::endl;
    std::cout << " Author: Fraser Love, me@fraserlove.com" << std::endl;
    std::cout << " Latest Release: 01/02/20" << std::endl;
    std::cout << " MIT Licience - Copyright (c) 2020 Fraser Love" << std::endl;
    std::cout << std::endl << " Entered Test Console. Type \"list\" for commands or \"quit\" to exit" << std::endl << std::endl;
}

void PrintCommands() {
    std::cout << " All Commands (Must be entered lower case):" << std::endl << std::endl;
	std::cout << "     set {index} {value}" << std::endl << "     push {value}" << std::endl << "     insert {index} {value}" << std::endl << "     clear" << std::endl;
	std::cout << "     reverse" << std::endl << "     show" << std::endl << "     show_as_string" << std::endl << "     show_debug" << std::endl;
    std::cout << "     length" << std::endl << "     find {value}" << std::endl << "     is_empty" << std::endl;
    std::cout << "     remove_value {value}" << std::endl << "     contains {value}" << std::endl << "     access" << std::endl;
    std::cout << "     access {index}" << std::endl << "     pop" << std::endl << "     peek" << std::endl << "     remove {idx}" << std::endl << "     to_array" << std::endl << std::endl;
}

void IOSystem(SinglyLinkedList<type>* list) {
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
		else if (cmd == "set") {
			std::cin >> idx >> value;
			list->Set(idx, value);
		}
		else if (cmd == "push") {
			std::cin >> value;
			list->Push(value);
		}
		else if (cmd == "insert") {
			std::cin >> idx >> value;
			list->Insert(idx, value);
		}
		else if (cmd == "clear") {
			list->Clear();
		}
		else if (cmd == "reverse") {
			list->Reverse();
		}
		else if (cmd == "show") {
			std::cout << " ";
			list->Show();
		}
		else if (cmd == "show_as_string") {
			std::cout << " ";
			list->ShowAsString();
		}
		else if (cmd == "show_debug") {
			std::cout << " ";
			list->ShowDebug();
		}
		else if (cmd == "length") {
			std::cout << " " << list->Length() << std::endl;
		}
		else if (cmd == "find") {
			std::cin >> idx;
			std::cout << " " << list->Find(idx) << std::endl;
		}
		else if (cmd == "is_empty") {
			std::cout << " " << list->IsEmpty() << std::endl;
		}
		else if (cmd == "remove_value") {
			std::cin >> value;
			std::cout << " " << list->RemoveValue(value) << std::endl;
		}
		else if (cmd == "contains") {
			std::cin >> value;
			std::cout << " " << list->Contains(value) << std::endl;
		}
		else if (cmd == "access") {
			std::cin >> idx;
			std::cout << " " << list->Access(idx) << std::endl;
		}
		else if (cmd == "pop") {
			std::cout << " " << list->Pop() << std::endl;
		}
		else if (cmd == "peek") {
			std::cout << " " << list->Peek() << std::endl;
		}
		else if (cmd == "remove") {
			std::cin >> idx;
			std::cout << " " << list->Remove(idx) << std::endl;
		}
		else if (cmd == "to_array") {
			ArrayStruct<type>* array_struct = list->ToArray();
			std::cout << "Array Pointer: " << array_struct->array << std::endl;
			std::cout << "Array Size: " << array_struct->size << std::endl;
			delete array_struct;
		}
		else {
			std::cout << "ERROR: Invalid Command '" << cmd << "' entered" << std::endl;
		}
		std::cin.ignore(INT_MAX, '\n');
	}
}

int main() {
    SinglyLinkedList<type> list;
    IOSystem(&list);
}
