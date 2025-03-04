/**
 * @file pqueue.h
 * @brief Priority queue implementation using binary heaps.
 * 
 * This class implements a priority queue using a binary heap stored in a dynamic array.
 * It supports both min-heap (default) and max-heap configurations and provides
 * efficient push/pop operations with O(log n) complexity.
 *
 * @tparam T The data type stored in the priority queue.
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include "vector.h"

/**
 * @class PQueue
 * @brief A priority queue implemented as a binary heap.
 *
 * @tparam T The data type stored in the priority queue.
 */
template <class T>
class PQueue {
private:
	Vector<T>* heap;
	bool max_heap;

	/**
	 * @brief Restablishes the heap property, moving upwards.
	 * @param idx The index of the node to move up.
	 */
	void heapifyUp(int idx);

	/**
	 * @brief Restablishes the heap property, moving downwards.
	 * @param idx The index of the node to move down.
	 */
	void heapifyDown(int idx);

	/**
	 * @brief Swaps two nodes using their indices.
	 * @param idx_1 The index of the first node.
	 * @param idx_2 The index of the second node.
	 */
	void swap(int idx_1, int idx_2);

	/**
	 * @brief Returns the index of a parent at a specific index.
	 * @param idx The index of the child node.
	 * @return The index of the parent node.
	 */
	int parent(int idx) const { return (idx - 1) / 2; }

	/**
	 * @brief Returns the index of the left child at a specific index.
	 * @param idx The index of the parent node.
	 * @return The index of the left child node.
	 */
	int leftChild(int idx) const { return 2 * idx + 1; }

	/**
	 * @brief Returns the index of the right child at a specific index.
	 * @param idx The index of the parent node.
	 * @return The index of the right child node.
	 */
	int rightChild(int idx) const { return 2 * idx + 2; }

	/**
	 * @brief Checks how the node held at the first index compares with the node held at the second index.
	 * @param idx_1 The index of the first node.
	 * @param idx_2 The index of the second node.
	 * @return True if the node at idx_1 is greater than or equal to the node at idx_2, false otherwise.
	 */
	bool compare(int idx_1, int idx_2) const;

	/**
	 * @brief Removes a node at a specific index in the heap.
	 * @param idx The index of the node to remove.
	 * @return The data of the removed node.
	 * @throws std::runtime_error If the priority queue is empty.
	 */
	T remove(int idx);

public:
	/**
	 * @brief Constructs a new priority queue (O(1)).
	 * @param is_max Indicates whether the heap is a max-heap (true) or min-heap (false).
	 */
	PQueue(bool max_heap = false) : heap(new Vector<T>()), max_heap(max_heap) {}

	/**
	 * @brief Constructs a new priority queue with a specified size (O(1)).
	 * @param size The initial size of the priority queue.
	 * @param is_max Indicates whether the heap is a max-heap (true) or min-heap (false).
	 */
	PQueue(int size, bool max_heap = false) : heap(new Vector<T>(size)), max_heap(max_heap) {}

	/**
	 * @brief Constructs a new priority queue with data from an array (O(n)).
	 * @param data The array of elements to be added to the priority queue.
	 * @param size The number of elements in the array.
	 * @param is_max Indicates whether the heap is a max-heap (true) or min-heap (false).
	 */
	PQueue(T data[], int size, bool max_heap = false) : heap(new Vector<T>(size)), max_heap(max_heap) {
		for (int i = 0; i < size; i++) {
			heap->push(data[i]);
		}
		for (int i = (size / 2) - 1; i >= 0; i--) {
			heapifyDown(i);
		}
	}

	/**
	 * @brief Destroys the priority queue and frees the associated memory (O(1)).
	 */
	~PQueue() { delete heap; }

	/**
	 * @brief Inserts an element into the priority queue (O(log(n))).
	 * @param data The element to be added.
	 */
	void push(T data) { heap->push(data); heapifyUp(length() - 1); }

	/**
	 * @brief Clears the priority queue (O(1)).
	 */
	void clear() { delete heap; heap = new Vector<T>(); }

	/**
	 * @brief Displays the dynamic array used to represent the heap (O(n)).
	 */
	void debug() const { heap->debug(); }

	/**
	 * @brief Returns the length of the priority queue (O(1)).
	 * @return The number of elements in the priority queue.
	 */
	int length() const { return heap->length(); }

	/**
	 * @brief Finds the index of the first instance of a specific value in the priority queue (O(n)).
	 * @param data The value to search for.
	 * @return The index of the first instance of the value, or -1 if not found.
	 */
	int find(T data) const { return heap->find(data); }

	/**
	 * @brief Checks if the priority queue is empty (O(1)).
	 * @return True if the priority queue is empty, false otherwise.
	 */
	bool isEmpty() const { return length() == 0; }

	/**
	 * @brief Removes a specific value from the priority queue (O(n)).
	 * @param data The value to remove.
	 * @return True if the value was removed, false if not found.
	 */
	bool removeValue(T data);

	/**
	 * @brief Checks if the priority queue contains a specific element (O(n)).
	 * @param data The value to check for.
	 * @return True if the value is in the priority queue, false otherwise.
	 */
	bool contains(T data) const;

	/**
	 * @brief Checks if the priority queue is a maximum heap (O(1)).
	 * @return True if the priority queue is a maximum heap, false otherwise.
	 */
	bool isMax() const { return max_heap; }

	/**
	 * @brief Checks if the priority queue is a minimum heap (O(1)).
	 * @return True if the priority queue is a minimum heap, false otherwise.
	 */
	bool isMin() const { return !max_heap; }
	
	/**
	 * @brief Checks if the heap property is still held (O(n)).
	 * @param idx The index to start checking from.
	 * @return True if the heap property is still held, false otherwise.
	 */
	bool validHeap(int idx = 0) const;

	/**
	 * @brief Removes and returns the lowest priority element in the priority queue (O(log(n))).
	 * @return The lowest priority element.
	 * @throws std::runtime_error If the priority queue is empty.
	 */
	T pop();

	/**
	 * @brief Returns the value of the element with the lowest priority in the priority queue (O(1)).
	 * @return The value of the element with the lowest priority.
	 * @throws std::runtime_error If the priority queue is empty.
	 */
	T peek() const;
};


template <class T>
bool PQueue<T>::removeValue(T data) {
	for (int i = 0; i < length(); i++) {
		if (heap->get(i) == data) {
			remove(i);
			return true;
		}
	}
	return false;
}

template <class T>
bool PQueue<T>::contains(T data) const {
	for (int i = 0; i < length(); i++) {
		if (heap->get(i) == data) {
			return true;
		}
	}
	return false;
}

template <class T>
bool PQueue<T>::validHeap(int idx) const {
	if (length() > 1) {
		if (idx >= length()) {
			return true;
		}
		int l_idx = leftChild(idx);
		int r_idx = rightChild(idx);
		if ((l_idx < length() && !compare(idx, l_idx)) || (r_idx < length() && !compare(idx, r_idx))) {
			return false;
		}
		return validHeap(l_idx) && validHeap(r_idx);
	}
	else {
		return true;
	}
}

template <class T>
T PQueue<T>::pop() {
	if (isEmpty()) {
		throw std::runtime_error("Cannot pop from an empty priority queue");
	}
	return remove(0);
}

template <class T>
T PQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::runtime_error("Cannot peek an empty priority queue");
	}
	return heap->get(0);
}

template <class T>
void PQueue<T>::heapifyUp(int idx) {
	int parent_idx = parent(idx);
	while (idx > 0 && compare(idx, parent_idx)) {
		swap(parent_idx, idx);
		idx = parent_idx;
		parent_idx = parent(idx);
	}
}

template <class T>
void PQueue<T>::heapifyDown(int idx) {
	int l_idx = leftChild(idx);
	int r_idx = rightChild(idx);
	int min_idx = idx;
	if ((l_idx < length()) && compare(l_idx, min_idx)) {
		min_idx = l_idx;
	}
	if ((r_idx < length()) && compare(r_idx, min_idx)) {
		min_idx = r_idx;
	}
	if (min_idx != idx) {
		swap(min_idx, idx);
		heapifyDown(min_idx);
	}
}

template <class T>
void PQueue<T>::swap(int idx_1, int idx_2) {
	T node_1 = heap->get(idx_1);
	T node_2 = heap->get(idx_2);
	heap->set(idx_1, node_2);
	heap->set(idx_2, node_1);
}

template <class T>
bool PQueue<T>::compare(int idx_1, int idx_2) const {
	T node_1 = heap->get(idx_1);
	T node_2 = heap->get(idx_2);
	if (!max_heap) {
		return (node_1 <= node_2);
	}
	return(node_1 >= node_2);
}

template <class T>
T PQueue<T>::remove(int idx) {
	if (isEmpty()) {
		throw std::runtime_error("Cannot remove from an empty priority queue");
	}
	
	T r_data = heap->get(idx);
	swap(idx, length() - 1);
	heap->remove(length() - 1);
	
	if (idx == length()) {
		return r_data;
	}
	
	T data = heap->get(idx);
	heapifyDown(idx);
	if (data == heap->get(idx)) {
		heapifyUp(idx);
	}
	return r_data;
}