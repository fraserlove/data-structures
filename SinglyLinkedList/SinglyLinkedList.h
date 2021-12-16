/**
 * Singly Linked List Data Structure Implementation
 * Author: Fraser Love, me@fraserlove.com
 * Created: 17/01/20
 * Latest Release: 01/02/20
 *
 * Singly linked list implementation. Includes tail pointer for constant time
 * insertion at the end of the linked list and length variable for recieving the
 * length of the list in constant time. Class allows for integer, float and
 * character data types.
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

template <typename T>
struct ArrayStruct {
    T* array;
    int size;
};

template <class T>
class SinglyLinkedList {
private:
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
	SinglyLinkedList(); // O(1)
	SinglyLinkedList(T data[], int size); // Linked list construction using data from an array, O(n)
	~SinglyLinkedList(); // Calls clear to deallocate all nodes from the heap, O(n)

	void Set(int idx, T data); // Sets the data the node at a specific position with the new data supplied, O(n)
	void Push(T data); // Adds a new node containing the value supplied to the end of the linked list, O(1)
	void Insert(int idx, T data); // Inserts a new node to the linked list at a specific location with the data specified, O(n)
	void Clear(); // Deallocates all nodes from the heap and resets len to zero, 0(n)
	void Reverse(); // Reverses the linked list by updating pointers to the previous node, O(n)
	void Show(); // Displays the entire linked list, O(n)
	void ShowAsString(); // Displays the entire linked list without any formatting, O(n)
	void ShowDebug(); // Displays the entire linked list, showing its structure and pointers for debugging, O(n)

	int Length(); // Returns the length of the linked list, O(1)
	int Find(T data); // Returns the position of the first instance of a specific value in the linked list, O(n)

	bool IsEmpty(); // Checks if the linked list is empty, O(1)
	bool RemoveValue(T data); // Removes the first instance of a node with a specific value in the linked list, O(n)
	bool Contains(T data); //  Checks if a value is present in the linked list, O(n)

	T Access(int idx); // Returns the object held in a specific node, O(n)
    T Pop(); // Removes the last node from the dynamic array and the data held in it, O(n)
	T Peek(); // Returns the value of the first node in the array, O(1)
	T Remove(int idx); // Removes a node by its position in the linked list and returns its value, O(n)

    ArrayStruct<T>* ToArray(); // Returns a struct holding a pointer to the first element in the array and the size of the array, O(n)
};

template class SinglyLinkedList<int>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<char>;