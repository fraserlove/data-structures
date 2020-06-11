/**
 * Priority Queue Data Structure Implementation using Binary Heaps
 * Author: Fraser Love, me@fraserlove.com
 * Created: 29/01/20
 * Latest Release: 01/02/20
 * 
 * Max and min priority queue implementation using binary heaps. Binary heaps
 * implemented using dynamic arrays in DynamicArray class present in Fraser's
 * data structure library included in "DynamicArray.h". Minimum priority queue
 * is default, with boolean heap_type avaliable so a maximum priority queue can
 * be created. Class allows for integer, float and character data types.
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

#include "DynamicArray.h"

template <class T>
class PQueue {
private:
	DynamicArray<T>* heap; // Binary heap implemented using a dynamic array from "DynamicArray.h"

	bool is_max_heap; // Operator used to change between max (true) or min (false) heaps

	void HeapifyUp(int idx); // Restablishes the heap property, moving upwards, O(log(n))
	void HeapifyDown(int idx); // Restablishes the heap property, moving downwards, O(log(n))
	void Swap(int idx_1, int idx_2); // Swaps two nodes using their indices, O(1)

	int Parent(int idx);  // Returns the index of a parent at a specific index, O(1)
	int LeftChild(int idx); // Returns the index of the left child at a specific index, O(1)
	int RightChild(int idx); // Returns the index of the left child at a specific index, O(1)

	bool Compare(int idx_1, int idx_2); // Checks how the node held at the first index compares with the node held at the second index, O(1)

	T Remove(int idx); // Removes a node at a specific index in the heap, O(n)

public:
	PQueue(bool heap_type = 0); // O(1)
	PQueue(int size, bool heap_type = 0); // O(1)
	PQueue(T data[], int size, bool heap_type = 0); // Priority queue construction using HeapfiyDown(), O(n)
	~PQueue(); // O(1)

	void Enqueue(T data); // Adds data to the priority queue and maintains the heap property, O(log(n))
	void Clear(); // Deallocates the heap from memory and creates a new heap, O(1)
	void ShowDebug(); // Displays the dynamic array used to represent the heap, O(n)

	int Length(); // Returns the length of the priority queue, O(1)
    int Find(int idx); // Returns the position of the first instance of a specific value in the priority queue, O(n)

	bool IsEmpty(); // Checks if the priority queue is empty, O(1)
	bool RemoveValue(T data); // Removes a specific value from the priority queue, O(n)
	bool Contains(T data); // Checks if the priority queue contains a specific element, O(n)
	bool IsMax(); // Checks if the priority queue is a maximum heap, O(n)
    bool IsMin(); // Checks if the priority queue is a minimum heap, O(n)
	bool ValidHeap(int idx = 0); // For debug, checks if the heap propery is still held, O(n)

	T Dequeue(); // Removes and returns the lowest priority element in the priority queue, O(log(n))
	T Peek(); // Returns the value of the element with the lowest priority in the priority queue , O(1)
};

template class PQueue<int>;
template class PQueue<float>;
template class PQueue<char>;