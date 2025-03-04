/**
 * @file list.h
 * @brief Singly linked list implementation with O(1) tail insertion.
 * 
 * This class implements a singly linked list with constant-time tail insertion.
 * 
 * @tparam T The data type stored in the linked list.
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include "vector.h"

/**
 * @class List
 * @brief A singly linked list with O(1) tail insertion.
 * 
 * @tparam T The data type stored in the linked list.
 */
template <class T>
class List {
private:
	/**
	 * @struct Node
	 * @brief A node in the linked list.
	 *
	 * Contains the data and a pointer to the next node.
	 */
	struct Node {
		T data;
		Node* next;
	};

	Node* head;
	Node* curr;
	Node* temp;
	Node* tail;

	int len;

public:
	/**
	 * @brief Constructs a new linked list (O(1)).
	 */
	List() : head(nullptr), curr(nullptr), temp(nullptr), tail(nullptr), len(0) {}

	/**
	 * @brief Constructs a new linked list with data from an array (O(n)).
	 * @param data An array of data to initialize the list.
	 * @param size The size of the array.
	 */
	List(T data[], int size) : head(nullptr), curr(nullptr), temp(nullptr), tail(nullptr), len(0) {
		for (int i = 0; i < size; i++) {
			push(data[i]);
		}
	}

	/**
	 * @brief Destroys the linked list and frees the associated memory (O(n)).
	 */
	~List() { clear(); }

	/**
	 * @brief Sets the data of a node at a specific index (O(n)).
	 * @param idx The index of the node to set.
	 * @param data The new data to set.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	void set(int idx, T data);

	/**
	 * @brief Adds a new node to the end of the list (O(1)).
	 * @param data The data to add.
	 */
	void push(T data) { insert(len, data); }

	/**
	 * @brief Inserts a new node at a specific index (O(n)).
	 * @param idx The index to insert the new node at.
	 * @param data The data to add.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	void insert(int idx, T data);

	/**
	 * @brief Clears the linked list and frees the associated memory (O(n)).
	 */
	void clear();

	/**
	 * @brief Reverses the linked list (O(n)).
	 * @throws std::runtime_error If the list is empty.
	 */
	void reverse();

	/**
	 * @brief Displays the linked list (O(n)).
	 */
	void show();

	/**
	 * @brief Displays the linked list, showing its structure and pointers for debugging (O(n)).
	 */
	void debug();

	/**
	 * @brief Returns the length of the linked list (O(1)).
	 * @return The length of the linked list.
	 */
	int length() const { return len; }

	/**
	 * @brief Finds the index of the first occurrence of a specific value in the linked list (O(n)).
	 * @param data The value to find.
	 * @return The index of the first occurrence of the value, or -1 if not found.
	 */
	int find(T data);

	/**
	 * @brief Checks if the linked list is empty (O(1)).
	 * @return True if the linked list is empty, false otherwise.
	 */
	bool isEmpty() const { return len == 0; }

	/**
	 * @brief Removes the first instance of a node with a specific value in the linked list (O(n)).
	 * @param data The value to remove.
	 * @return True if the node was removed, false otherwise.
	 */
	bool removeValue(T data);

	/**
	 * @brief Checks if a value is present in the linked list (O(n)).
	 * @param data The value to check.
	 * @return True if the value is present, false otherwise.
	 */
	bool contains(T data) { return find(data) != -1; }

	/**
	 * @brief Returns the object held in a specific node (O(n)).
	 * @param idx The index of the node.
	 * @return The data held in the node.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	T get(int idx);

	/**
	 * @brief Removes the last node from the linked list and returns its value (O(n)).
	 * @return The value of the last node.
	 * @throws std::runtime_error If the list is empty.
	 */
	T pop();

	/**
	 * @brief Returns the value of the first node in the list (O(1)).
	 * @return The value of the first node.
	 * @throws std::runtime_error If the list is empty.
	 */
	T peek() const { if (isEmpty()) throw std::runtime_error("Cannot peek an empty list"); return head->data; }

	/**
	 * @brief Removes a node by its position in the linked list and returns its value (O(n)).
	 * @param idx The index of the node to remove.
	 * @return The value of the removed node.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	T remove(int idx);

	/**
	 * @brief Converts the linked list to a Vector (O(n)).
	 * @return A pointer to the new Vector.
	 */
	Vector<T>* toVector();
};


template <class T>
void List<T>::set(int idx, T data) {
	if (idx >= len || idx < 0 || isEmpty()) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	curr = head;
	int cur_idx = 0;
	while (cur_idx != idx) {
		curr = curr->next;
		cur_idx++;
	}
	curr->data = data;
}

template <class T>
void List<T>::insert(int idx, T data) {
	if (idx > len || idx < 0) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;
	
	if (idx == 0) {
		new_node->next = head;
		head = new_node;
		if (tail == nullptr) {
			tail = new_node;
		}
	} else if (idx == len) {
		if (head != nullptr) {
			tail->next = new_node;
			tail = new_node;
		} else {
			head = tail = new_node;
		}
	} else {
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
	
	len++;
}

template <class T>
void List<T>::clear() {
	curr = head;
	while (curr != nullptr) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	len = 0;
	head = tail = nullptr;
}

template <class T>
void List<T>::reverse() {
	if (isEmpty()) {
		throw std::runtime_error("Cannot reverse an empty list");
	}
	
	tail = head;
	Node* prev = nullptr;
	curr = head;
	
	while (curr != nullptr) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	
	head = prev;
}

template <class T>
void List<T>::show() {
	curr = head;
	while (curr != nullptr) {
		if (curr != head) {
			std::cout << ", ";
		}
		std::cout << curr->data;
		curr = curr->next;
	}
	std::cout << std::endl;
}

template <class T>
void List<T>::debug() {
	curr = head;
	while (curr != nullptr) {
		std::cout << "|" << curr->data << ": " << &curr->data << "|" << "--" << curr->next << "-->  ";
		curr = curr->next;
	}
	std::cout << std::endl << "Tail: " << tail << std::endl;
}

template <class T>
int List<T>::find(T data) {
	curr = head;
	for (int i = 0; i < len; i++) {
		if (curr->data == data) {
			return i;
		}
		curr = curr->next;
	}
	return -1;
}

template <class T>
bool List<T>::removeValue(T data) {	
	temp = nullptr;
	curr = head;
	
	while (curr != nullptr && curr->data != data) {
		temp = curr;
		curr = curr->next;
	}
	
	if (curr == nullptr) {
		return false;
	}
	
	Node* del_ptr = curr;
	
	if (del_ptr == head) {
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
	} else if (del_ptr == tail) {
		tail = temp;
		temp->next = nullptr;
	} else {
		temp->next = curr->next;
	}
	
	delete del_ptr;
	len--;
	return true;
}

template <class T>
T List<T>::get(int idx) {
	if (idx >= len || idx < 0 || isEmpty()) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	curr = head;
	int cur_idx = 0;
	while (cur_idx != idx) {
		curr = curr->next;
		cur_idx++;
	}
	return curr->data;
}

template <class T>
T List<T>::pop() {
	if (isEmpty()) {
		throw std::runtime_error("Cannot pop from an empty list");
	}
	
	if (head == tail) {
		T r_data = head->data;
		delete head;
		head = tail = nullptr;
		len = 0;
		return r_data;
	}
	
	temp = head;
	while (temp->next != tail) {
		temp = temp->next;
	}
	
	T r_data = tail->data;
	delete tail;
	tail = temp;
	tail->next = nullptr;
	len--;
	return r_data;
}

template <class T>
T List<T>::remove(int idx) {
	if (idx >= len || idx < 0 || isEmpty()) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	Node* del_ptr;
	
	if (idx == 0) {
		del_ptr = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
	} else {
		temp = curr = head;
		int cur_idx = 0;
		while (cur_idx != idx) {
			temp = curr;
			curr = curr->next;
			cur_idx++;
		}
		del_ptr = curr;
		temp->next = curr->next;
		if (del_ptr == tail) {
			tail = temp;
		}
	}
	
	T r_data = del_ptr->data;
	delete del_ptr;
	len--;
	return r_data;
}

template <class T>
Vector<T>* List<T>::toVector() {
	Vector<T>* vector = new Vector<T>(len);
	curr = head;
	while (curr != nullptr) {
		vector->push(curr->data);
		curr = curr->next;
	}
	return vector;
}