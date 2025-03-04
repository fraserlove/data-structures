/**
 * @file queue.h
 * @brief Queue implementation using singly linked lists.
 * 
 * This class implements a queue using a singly linked list.
 * It provides O(1) push and pop operations with the underlying list class.
 * 
 * @tparam T The data type stored in the queue.
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include "list.h"

/**
 * @class Queue
 * @brief A queue implemented using a singly linked list.
 * 
 * @tparam T The data type stored in the queue.
 */
template <class T>
class Queue {
private:
	List<T> list;

public:
	/**
	 * @brief Constructs an empty queue (O(1)).
	 */
	Queue() {}

	/**
	 * @brief Constructs a queue with a single element (O(1)).
	 * @param data The data to push into the queue.
	 */
	Queue(T data) { push(data); }

	/**
	 * @brief Constructs a queue with elements from an array (O(n)).
	 * @param data The array of data to push into the queue.
	 * @param size The size of the array.
	 */
	Queue(T data[], int size) {
		for (int i = 0; i < size; i++) {
			push(data[i]);
		}
	}
	
	/**
	 * @brief Destroys the queue (O(n)).
	 */
	~Queue() {}

	/**
	 * @brief Adds an element to the back of the queue (O(1)).
	 * @param data The data to push into the queue.
	 */
	void push(T data) { list.push(data); }

	/**
	 * @brief Clears the queue (O(n)).
	 */
	void clear() { list.clear(); }

	/**
	 * @brief Displays the queue (O(n)).
	 */
	void show() const { list.show(); }

	/**
	 * @brief Returns the length of the queue (O(1)).
	 * @return The length of the queue.
	 */
	int length() const { return list.length(); }

	/**
	 * @brief Checks if the queue is empty (O(1)).
	 * @return True if the queue is empty, false otherwise.
	 */
	bool isEmpty() const { return list.isEmpty(); }

	/**
	 * @brief Removes an element from the front of the queue (O(1)).
	 * @return The data removed from the queue.
	 * @throws std::runtime_error If the queue is empty.
	 */
	T pop() { if (isEmpty()) throw std::runtime_error("Cannot pop from an empty queue"); return list.remove(0); }

	/**
	 * @brief Returns the element at the front of the queue without removing it (O(1)).
	 * @return The data at the front of the queue.
	 * @throws std::runtime_error If the queue is empty.
	 */
	T peek() const { if (isEmpty()) throw std::runtime_error("Cannot peek an empty queue"); return list.peek(); }
};