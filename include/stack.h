/**
 * @file stack.h
 * @brief Stack implementation using singly linked lists.
 * 
 * This class implements a stack using a singly linked list.
 * It provides O(1) push and pop operations with the underlying list class.
 * 
 * @tparam T The data type stored in the stack.
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include "list.h"

/**
 * @class Stack
 * @brief A stack implemented using a singly linked list.
 * 
 * @tparam T The data type stored in the stack.
 */
template <class T>
class Stack {
private:
	List<T> list;

public:
	/**
	 * @brief Constructs an empty stack (O(1)).
	 */
	Stack() {}

	/**
	 * @brief Constructs a stack with a single element (O(1)).
	 * @param data The data to push onto the stack.
	 */
	Stack(T data) { push(data); }

	/**
	 * @brief Constructs a stack with elements from an array (O(n)).
	 * @param data The array of data to push onto the stack.
	 * @param size The size of the array.
	 */
	Stack(T data[], int size) {
		for (int i = 0; i < size; i++) {
			push(data[i]);
		}
	}

	/**
	 * @brief Destroys the stack (O(n)).
	 */
	~Stack() {}

	/**
	 * @brief Pushes an element onto the stack (O(1)).
	 * @param data The data to push onto the stack.
	 */
	void push(T data) { list.insert(0, data); }

	/**
	 * @brief Clears the stack (O(n)).
	 */
	void clear() { list.clear(); }

	/**
	 * @brief Displays the stack (O(n)).
	 */
	void show() const { list.show(); }

	/**
	 * @brief Returns the length of the stack (O(1)).
	 * @return The length of the stack.
	 */
	int length() const { return list.length(); }

	/**
	 * @brief Checks if the stack is empty (O(1)).
	 * @return True if the stack is empty, false otherwise.
	 */
	bool isEmpty() const { return list.isEmpty(); }

	/**
	 * @brief Pops an element off the stack (O(1)).
	 * @return The data popped from the stack.
	 * @throws std::runtime_error If the stack is empty.
	 */
	T pop() { if (isEmpty()) throw std::runtime_error("Cannot pop from an empty stack"); return list.remove(0); }

	/**
	 * @brief Returns the element at the top of the stack without removing it (O(1)).
	 * @return The data at the top of the stack.
	 * @throws std::runtime_error If the stack is empty.
	 */
	T peek() const { if (isEmpty()) throw std::runtime_error("Cannot peek an empty stack"); return list.peek(); }
};