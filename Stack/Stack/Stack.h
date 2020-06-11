/*
 * Stack Data Structure Implementation using Singly Linked Lists
 * Author: Fraser Love, me@fraserlove.com
 * Created: 27/01/20
 * Latest Release: 02/02/20
 *
 * Stack implementation using singly linked lists. Linked lists implemented using
 * in SinglyLinkedList class present in Fraser's data structure library included
 * in "SinglyLinkedList.h". Singly Linked list class insertion at tail and
 * deletion at head provide for constant time Push() and Pop() operations.
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
class Stack {
private:
	SinglyLinkedList<T> list; // List used to represent the stack from "SinglyLinkedList.h"

public:
	Stack(); // O(1)
	Stack(T data); // O(1)
	Stack(T data[], int size); // Stack construction using data from an array, O(n)
	~Stack(); // Deallocates all elements in the stack from the heap, O(n)

	void Push(T data); // Push an element on the stack, O(1)
	void Clear(); // Deallocates all nodes on the stack from the heap and resets the height of the to stack to 0, 0(n)
	void Show(); // Displays all elements on the stack, O(n)

	int Length(); // Return the number of elements on the stack, O(1)

	bool IsEmpty(); // Check if the stack is empty, O(1)

	T Pop(); // Pops an element off the stack, O(1)
	T Peek(); // Returns the element at the top of the stack without removing it, O(1)
};

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
