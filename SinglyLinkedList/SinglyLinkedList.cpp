#include <iostream>

#include "SinglyLinkedList.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = tail = NULL;
	len = 0;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T data[], int size) {
	head = tail = NULL;
	len = 0;
	for (int i = 0; i < size; i++) {
		Push(data[i]);
	}
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList () {
	Clear();
}

template <class T>
void SinglyLinkedList<T>::Set(int idx, T data) {
	curr = head;
	int cur_idx = 0;
	if (idx >= len || idx < 0 || IsEmpty()) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		while (cur_idx != idx) {
			curr = curr->next;
			cur_idx++;
		}
		curr->data = data;
	}
}

template <class T>
void SinglyLinkedList<T>::Push(T data) {
	Node* new_node = new Node;
	new_node->next = NULL;
	new_node->data = data;
	if (head != NULL) {
		tail->next = new_node;
	}
	else {
		head = tail = new_node;
	}
	tail = new_node;
	len++;
}

template <class T>
void SinglyLinkedList<T>::Insert(int idx, T data) {
	if (idx == len) {
		Push(data);
	}
	else if (idx > len - 1 || idx < 0) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		Node* new_node = new Node;
		new_node->data = data;
		if (idx == 0) {
			new_node->next = head;
			head = new_node;
		}
		else {
			temp = curr = head;
			int cur_idx = 0;
			while (cur_idx != idx) {
				temp = curr;
				curr = curr->next;
				cur_idx++;
			}
			temp->next = new_node;
			new_node->next = curr;
		}
		tail = new_node;
		len++;
	}
}

template <class T>
void SinglyLinkedList<T>::Clear() {
	temp = curr = head;
	while (curr != NULL) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	len = 0;
	head = tail = NULL;
}

template <class T>
void SinglyLinkedList<T>::Reverse() {
	if (IsEmpty()) {
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else {
		tail = curr = head;
		temp = curr->next;
		curr->next = NULL;

		while (temp != NULL) {
			Node* prev = temp->next;
			temp->next = curr;
			curr = temp;
			temp = prev;
		}
		head = curr;
	}
}

template <class T>
void SinglyLinkedList<T>::Show() {
	curr = head;
	while (curr != NULL) {
		if (curr == head) {
			std::cout << curr->data;
		}
		else {
			std::cout << ", " << curr->data;
		}
		curr = curr->next;
	}
	std::cout << std::endl;
}

template <class T>
void SinglyLinkedList<T>::ShowAsString(){
	curr = head;
	while (curr != NULL) {
		std::cout << curr->data;
		curr = curr->next;
	}
	std::cout << std::endl;
}

template <class T>
void SinglyLinkedList<T>::ShowDebug() {
	curr = head;
	while (curr != NULL) {
		if (curr == head) {
			std::cout << "List Structure: |" << curr->data << ": " << &curr->data << "|" << "--" << curr->next << "-->  ";
		}
		else {
			std::cout << "|" << curr->data << ": " << &curr->data << "|" << "--" << curr->next << "-->  ";
		}
		curr = curr->next;
	}
	std::cout << std::endl << "Tail: " << tail << std::endl;
}

template <class T>
int SinglyLinkedList<T>::Length() { return len; }

template <class T>
int SinglyLinkedList<T>::Find(T data) {
	temp = curr = head;
	for (int i = 0; i < len; i++) {
		if (curr->data != data) {
			curr = curr->next;
		}
		else {
			return i;
		}
	}
	return -1;
}

template <class T>
bool SinglyLinkedList<T>::IsEmpty() { return Length() == 0; }

template <class T>
bool SinglyLinkedList<T>::RemoveValue(T data) {
	temp = curr = head;
	while (curr != NULL && curr->data != data) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		return false;
	}
	else {
		Node* del_ptr = curr;
		curr = curr->next;
		temp->next = curr;
		if (del_ptr == head) {
			head = head->next;
		}
		else if (del_ptr == tail) {
			tail = temp;
		}
		delete del_ptr;
		len--;
		return true;
	}
}

template <class T>
bool SinglyLinkedList<T>::Contains(T data) { return Find(data) != -1; }

template <class T>
T SinglyLinkedList<T>::Access(int idx) {
	curr = head;
	int cur_idx = 0;
	if (idx >= len || idx < 0 || IsEmpty()) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		while (cur_idx != idx) {
			curr = curr->next;
			cur_idx++;
		}
		return curr->data;
	}
}

template <class T>
T SinglyLinkedList<T>::Pop() {
	temp = curr = head;
	if (IsEmpty()) {
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else {
		while (curr != tail) {
			temp = curr;
			curr = curr->next;
		}
		T r_data = curr->data;
		delete curr;
		temp->next = NULL;
		tail = temp;
		return r_data;
	}
}

template <class T>
T SinglyLinkedList<T>::Peek() {
	if (IsEmpty()) {
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else {
		return head->data;
	}
}

template <class T>
T SinglyLinkedList<T>::Remove(int idx) {
	temp = curr = head;
	if (idx >= len || idx < 0 || IsEmpty()) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		Node* del_ptr = head;
		if (idx == 0) {
			head = head->next;
		}
		else {
			int cur_idx = 0;
			while (cur_idx != idx) {
				temp = curr;
				curr = curr->next;
				cur_idx++;
			}
			del_ptr = curr;
			curr = curr->next;
			temp->next = curr;
			if (del_ptr == tail) {
				tail = temp;
			}
		}
		T r_data = del_ptr->data;
		delete del_ptr;
		len--;
		return r_data;
	}
}

template <class T>
ArrayStruct<T>* SinglyLinkedList<T>::ToArray() {
	ArrayStruct<T>* new_array = new ArrayStruct<T>;
	new_array->array = new T[len];
	new_array->size = len;
	curr = head;
	int cur_idx = 0;
	while (curr != NULL) {
		new_array->array[cur_idx] = curr->data;
		curr = curr->next;
		cur_idx++;
	}
	return new_array;
}