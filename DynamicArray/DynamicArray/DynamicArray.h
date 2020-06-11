/**
 * Dynamic Array Data Structure Implementation using Static Arrays
 * Author: Fraser Love, me@fraserlove.com
 * Created: 24/01/20
 * Latest Release: 01/02/20
 *
 * Dynamic array implementation using static arrays with dynamic resising.
 * Dynamic resizing includes checking if the new static array should resize,
 * taking into account future additions/removals and copying all elements to
 * a new static array. The rate of dynamic resizing for array growth and decay
 * can be controlled for either, shorter average Pop(), Push(), Insert() and
 * Remove() calls, or improved space complexity. Class allows for integer, 
 * float and character data types.
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

template <class T>
class DynamicArray {
private:
	T* s_array;
	int len;
	int cap;

	const int GROWTH_FACTOR = 2; // Rate of dynamic resizing for growth operations Push() and Insert(), higher value decreases average function call to growth operations, lower decreases space used by static array
	const int DECAY_FACTOR = 4; // Rate of dynamic resizing for decay operations Pop() and Remove(), higher value decreases average function call to decay operations, lower decreases space used by static array
	const int MIN_CAPACITY = 1; // The minimum capacity of the static array

public:
	DynamicArray(); // O(1)
	DynamicArray(int size); // O(1)
	DynamicArray(T data[], int size); // Initialises dynamic array with values from a static array, O(n)
	~DynamicArray(); // O(1)

	void Set(int idx, T data); // Sets an index in the dynamic array to a particular value, O(1)
	void Push(T data); // Adds a single value to the end of the dynamic array, O(1)
	void Push(T data[], int size); // Adds a static array of values to the end of the dynamic array, O(k)
	void Insert(int idx, T data); // Adds a single value to a particular index in the dynamic array, O(n)
	void Insert(int idx, T data[], int size); // Adds a static array of values to a particular index in the dynamic array, O(n*k)
	void Clear(); // Deallocates the static array from memory and creates a new static array of minimum length, O(1)
	void Reverse(); // Reverses all elements in the dynamic array, O(n)
	void Show(); // Displays the dynamic array, O(n)
	void ShowAsString(); // Displays the dynamic array without any formatting, O(n)
	void ShowDebug(); // Displays the entire dynamic array, showing the total capacity of the static array and the section currently in use, O(n)
	
	int Length(); // Returns the length of the dynamic array, O(1)
	int Find(T data); // Returns the position of the first instance of a specific value in the dynamic array, O(n)

	bool IsEmpty(); // Checks if the dynamic array is empty, O(1)
	bool RemoveValue(T data); // Removes a specific value from the dynamic array, O(n)
	bool Contains(T data); //  Checks if a value is present in the dynamic array, O(n)

	T Access(int idx); // Returns the value held at a specific index in the dynamic array, O(1)
	T Pop(); // Removes the last element from the dynamic array and returns its value, O(1)
	T Remove(int idx); // Removes a particular element by its index in the dynamic array and returns its value, O(n)

	DynamicArray<int>* FindAll(T data); // Returns a new dynamic array of all of the indices where an instance of a specific value was found, O(n)
};

template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<char>;