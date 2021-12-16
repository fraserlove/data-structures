#include <iostream>

#include "Queue.h"

template <class T>
Queue<T>::Queue() {}

template <class T>
Queue<T>::Queue(T data) { Enqueue(data); }

template <class T>
Queue<T>::Queue(T data[], int size) {
	for (int i = 0; i < size; i++) {
		Enqueue(data[i]);
	}
}

template <class T>
Queue<T>::~Queue() { list.~SinglyLinkedList(); }

template <class T>
void Queue<T>::Enqueue(T data) { list.Push(data); }

template <class T>
void Queue<T>::Clear() { list.Clear(); }

template <class T>
void Queue<T>::Show() {
	std::cout << "Front: ";
	list.Show();
}

template <class T>
int Queue<T>::Length() { return list.Length(); }

template <class T>
bool Queue<T>::IsEmpty() { return Length() == 0; }

template <class T>
T Queue<T>::Dequeue() {
	if (IsEmpty()) {
		std::cout << "ERROR: Queue is empty" << std::endl;
	}
	else {
		return list.Remove(0);
	}
}

template <class T>
T Queue<T>::Peek() {
	if (IsEmpty()) {
		std::cout << "ERROR: Queue is empty" << std::endl;
	}
	else {
		return list.Peek();
	}
}