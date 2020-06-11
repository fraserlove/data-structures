/**
 * Queue Data Structure Implementation using Singly Linked Lists
 * Author: Fraser Love, me@fraserlove.com
 * Created: 28/01/20
 * Latest Release: 02/02/20
 *
 * Queue implementation using singly linked lists. Linked lists implemented using
 * in SinglyLinkedList class present in Fraser's data structure library included
 * in "SinglyLinkedList.h". Singly Linked list class insertion at tail and
 * deletion at head provide for constant time Enqueue() and Dequeue() operations.
 * Class allows for integer, float and character data types.
 *
 * =============================================================================
 * MIT License
 *
 * Copyright (c) 2020 Fraser Love
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * =============================================================================
 **/

#pragma once

#include "SinglyLinkedList.h"

template <class T>
class Queue {
private:
	SinglyLinkedList<T> list; // List used to represent the queue from "SinglyLinkedList.h"

public:
	Queue(); // O(1)
	Queue(T data); // O(1)
	Queue(T data[], int size); // Queue construction using data from an array, O(n)
	~Queue(); // Deallocates all elements in the queue from the heap, O(n)

	void Enqueue(T data); // Add an element to the back of the queue, O(1)
	void Clear(); // Deallocates all nodes in the queue from the heap and resets the length of the to queue to 0, 0(n)
	void Show(); // Displays all elements in the queue, O(n)

	int Length(); // Return the number of elements in the queue, O(1)

	bool IsEmpty(); // Check if the queue is empty, O(1)

	T Dequeue(); // Remove an element from the front of the queue, O(1)
	T Peek(); // Returns the element at the front of the queue without removing it, O(1)
};

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;