#include <iostream>

#include "Stack.h"

template <class T>
Stack<T>::Stack() {}

template <class T>
Stack<T>::Stack(T data) { Push(data); }

template <class T>
Stack<T>::Stack(T data[], int size) {
	for (int i = 0; i < size; i++) {
		Push(data[i]);
	}
}

template <class T>
Stack<T>::~Stack() { list.~SinglyLinkedList(); }

template <class T>
void Stack<T>::Push(T data) { list.Insert(0, data); }

template <class T>
void Stack<T>::Clear() { list.Clear(); }

template <class T>
void Stack<T>::Show() {
	std::cout << "Top: ";
	list.Show();
}

template <class T>
int Stack<T>::Length() { return list.Length(); }

template <class T>
bool Stack<T>::IsEmpty() { return Length() == 0; }

template <class T>
T Stack<T>::Pop() {
	if (IsEmpty()) {
		std::cout << "ERROR: Stack is empty" << std::endl;
	}
	else {
		return list.Remove(0);
	}
}

template <class T>
T Stack<T>::Peek() {
	if (IsEmpty()) {
		std::cout << "ERROR: Stack is empty" << std::endl;
	}
	else {
		return list.Peek();
	}
}