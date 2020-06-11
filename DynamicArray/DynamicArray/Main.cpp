/**
 * Dynamic Array Data Structure Implementation using Static Arrays
 * Author: Fraser Love, me@fraserlove.com
 * Created: 24/01/20
 * Latest Release: 01/02/20
 *
 * This file is a standalone console IO system for interfacing with the dynamic
 * array data structure declared in "DynamicArray.h". The data struture itself
 * is functionally independent from this file which is only used for demonstration
 * and testing purposes. All bugs and general issues with this data structue are
 * welcomed and can be submitted at the repository page on Github.
 *
 * All files included in this repository are protected by
 * the MIT Licence - Copyright (c) 2020 Fraser Love. See "DynamicArray.h" or
 * "LICENCE.txt" at the root of this repository for licencing details.
 **/

#include <iostream>
#include <climits>

#include "DynamicArray.h"

typedef int type;

void PrintHeader() {
    std::cout << " Dynamic Array Data Structure Implementation using Static Arrays" << std::endl;
    std::cout << " Author: Fraser Love, me@fraserlove.com" << std::endl;
    std::cout << " Latest Release: 01/02/20" << std::endl;
    std::cout << " MIT Licience - Copyright (c) 2020 Fraser Love" << std::endl;
    std::cout << std::endl << " Entered Test Console. Type \"list\" for commands or \"quit\" to exit" << std::endl << std::endl;
}

void PrintCommands() {
    std::cout << " All Commands (Must be entered lower case):" << std::endl << std::endl;
	std::cout << "     set {index} {value}" << std::endl << "     push {value}" << std::endl << "     insert {index} {value}" << std::endl;
	std::cout << "     clear" <<  std::endl << "     reverse" << std::endl << "     show" << std::endl << "     show_as_string" << std::endl << "     show_debug" << std::endl;
    std::cout << "     length" << std::endl << "     find {value}" << std::endl << "     is_empty" << std::endl << "     remove_value {value}" << std::endl;
    std::cout << "     contains {value}" << std::endl << "     access {index}" << std::endl << "     pop" << std::endl << "     remove" << std::endl << std::endl;
}

void IOSystem(DynamicArray<type>* array) {
	bool session = true;
	std::string cmd;
	std::string str_array;
	type value;
	int idx;
	int size;
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
			array->Set(idx, value);
		}
		else if (cmd == "push") {
			std::cin >> value;
			array->Push(value);
		}
		else if (cmd == "insert") {
			std::cin >> idx >> value;
			array->Insert(idx, value);
		}
		else if (cmd == "clear") {
			array->Clear();
		}
		else if (cmd == "reverse") {
			array->Reverse();
		}
		else if (cmd == "show") {
			std::cout << " ";
			array->Show();
		}
		else if (cmd == "show_as_string") {
			std::cout << " ";
			array->ShowAsString();
		}
		else if (cmd == "show_debug") {
			std::cout << " ";
			array->ShowDebug();
		}
		else if (cmd == "length") {
			std::cout << " " << array->Length() << std::endl;
		}
		else if (cmd == "find") {
			std::cin >> value;
			std::cout << " " << array->Find(value) << std::endl;
		}
		else if (cmd == "is_empty") {
			std::cout << " " << array->IsEmpty() << std::endl;
		}
		else if (cmd == "remove_value") {
			std::cin >> value;
			std::cout << " " << array->RemoveValue(value) << std::endl;
		}
		else if (cmd == "contains") {
			std::cin >> value;
			std::cout << " " << array->Contains(value) << std::endl;
		}
		else if (cmd == "access") {
			std::cin >> idx;
			std::cout << " " << array->Access(idx) << std::endl;
		}
		else if (cmd == "pop") {
			std::cout << " " << array->Pop() << std::endl;
		}
		else if (cmd == "remove") {
			std::cin >> idx;
			std::cout << " " << array->Remove(idx) << std::endl;
		}
		else {
			std::cout << "ERROR: Invalid Command '" << cmd << "' entered" << std::endl;
		}
		std::cin.ignore(INT_MAX, '\n');
	}
}

int main() {
	DynamicArray<type> array;
	IOSystem(&array);
}
