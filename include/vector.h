/**
 * @file vector.h
 * @brief Vector (dynamic array) implementation using static arrays with automatic resizing.
 * 
 * Features configurable growth/decay factors to balance performance and memory usage.
 * 
 * @tparam T The data type stored in the vector.
 */

#pragma once

#include <iostream>
#include <stdexcept>

/**
 * @class Vector
 * @brief A dynamic array implementation using static arrays with automatic resizing.
 * 
 * @tparam T The data type stored in the vector.
 */
template <class T>
class Vector {
private:
	T* s_array;
	int len;
	int cap;

	// Rate of dynamic resizing for growth operations
	static const int GROWTH_FACTOR = 2;
	// Rate of dynamic resizing for decay operations
	static const int DECAY_FACTOR = 4;
	// The minimum capacity of the static array
	static const int MIN_CAPACITY = 1;

	/**
	 * @brief Grows the capacity of the vector by the growth factor.
	 */
	void grow() {
		cap = cap * GROWTH_FACTOR;
		T* new_array = new T[cap];
		for (int i = 0; i < len; i++) {
			new_array[i] = s_array[i];
		}
		delete[] s_array;
		s_array = new_array;
	}

	/**
	 * @brief Reduces the capacity of the vector by the decay factor.
	 */
	void decay() {
		cap = std::max(cap / DECAY_FACTOR, 1);
		T* new_array = new T[cap];
		for (int i = 0; i < len; i++) {
			new_array[i] = s_array[i];
		}
		delete[] s_array;
		s_array = new_array;
	}

public:
	/**
	 * @brief Constructs an empty vector with a capacity of 1 by default (O(1)).
	 * @param size The initial capacity of the vector.
	 */
	Vector(int size = MIN_CAPACITY) : len(0), cap(size), s_array(new T[size]) {}

	/**
	 * @brief Constructs a vector with elements from an array (O(n)).
	 * @param data The array of data to initialize the vector.
	 * @param size The size of the array.
	 */
	Vector(T data[], int size = 1) : len(size), cap(size), s_array(new T[size]) {
		for (int i = 0; i < size; i++) {
			s_array[i] = data[i];
		}
	}

	/**
	 * @brief Destroys the vector and frees all allocated memory (O(1)).
	 */
	~Vector() { delete[] s_array; }

	/**
	 * @brief Sets an index in the vector to a particular value (O(1)).
	 * @param idx The index to set.
	 * @param data The value to set at the index.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	void set(int idx, T data);

	/**
	 * @brief Adds a single value to the end of the vector (O(1)).
	 * @param data The value to add.
	 */
	void push(T data) { insert(len, data); }

	/**
	 * @brief Adds a static array of values to the end of the vector (O(n)).
	 * @param data The array of values to add.
	 * @param size The size of the array.
	 */
	void push(T data[], int size) { insert(len, data, size); }

	/**
	 * @brief Adds a single value to a particular index in the vector (O(n)).
	 * @param idx The index to insert at.
	 * @param data The value to insert.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	void insert(int idx, T data);

	/**
	 * @brief Adds a static array of values to a particular index in the vector (O(n*k)).
	 * @param idx The index to insert at.
	 * @param data The array of values to insert.
	 * @param size The size of the array.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	void insert(int idx, T data[], int size);

	/**
	 * @brief Clears the vector and resets the length and capacity (O(1)).
	 */
	void clear();

	/**
	 * @brief Reverses the vector (O(n)).
	 */
	void reverse();

	/**
	 * @brief Displays the vector (O(n)).
	 */
	void show() const;

	/**
	 * @brief Displays the vector, showing the total capacity of the static array and the section currently in use (O(n)).
	 */
	void debug() const;
	
	/**
	 * @brief Returns the length of the vector (O(1)).
	 * @return The length of the vector.
	 */
	int length() const { return len; }

	/**
	 * @brief Finds the first instance of a specific value in the vector (O(n)).
	 * @param data The value to find.
	 * @return The index of the value, or -1 if not found.
	 */
	int find(T data) const;

	/**
	 * @brief Checks if the vector is empty (O(1)).
	 * @return True if the vector is empty, false otherwise.
	 */
	bool isEmpty() const { return len == 0; }

	/**
	 * @brief Removes a specific value from the vector (O(n)).
	 * @param data The value to remove.
	 * @return True if the value was removed, false otherwise.
	 */
	bool removeValue(T data);

	/**
	 * @brief Checks if the vector contains a specific value (O(n)).
	 * @param data The value to check for.
	 * @return True if the value is present, false otherwise.
	 */
	bool contains(T data) const { return find(data) != -1; }

	/**
	 * @brief Returns the value held at a specific index in the vector (O(1)).
	 * @param idx The index to get the value from.
	 * @return The value at the index.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	T get(int idx) const;

	/**
	 * @brief Removes the last element from the vector and returns its value (O(1)).
	 * @return The value of the last element.
	 * @throws std::runtime_error If the vector is empty.
	 */
	T pop();

	/**
	 * @brief Removes a particular element by its index in the vector and returns its value (O(n)).
	 * @param idx The index of the element to remove.
	 * @return The value of the removed element.
	 * @throws std::out_of_range If the index is out of bounds.
	 */
	T remove(int idx);

	/**
	 * @brief Returns a new vector of all of the indices where an instance of a specific value was found (O(n)).
	 * @param data The value to find.
	 * @return A new vector of indices.
	 */
	Vector<int>* findAll(T data) const;
};

template <class T>
void Vector<T>::set(int idx, T data) {
	if (idx >= len || idx < 0) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	s_array[idx] = data;
}

template <class T>
void Vector<T>::insert(int idx, T data) {
	if (idx > len || idx < 0) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	if (len == cap) {
		grow();
	}
	
	if (idx < len) {
		for (int i = len; i > idx; i--) {
			s_array[i] = s_array[i - 1];
		}
	}
	
	s_array[idx] = data;
	len++;
}

template <class T>
void Vector<T>::insert(int idx, T data[], int size) {
	if (idx > len || idx < 0) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	for (int i = 0; i < size; i++) {
		insert(idx + i, data[i]);
	}
}

template <class T>
void Vector<T>::clear() {
	delete[] s_array;
	len = 0;
	cap = MIN_CAPACITY;
	s_array = new T[cap];
}

template <class T>
void Vector<T>::reverse() {
	T* new_array = new T[cap];
	for (int i = 0; i < len; i++) {
		new_array[i] = s_array[len - i - 1];
	}
	delete[] s_array;
	s_array = new_array;
}

template <class T>
void Vector<T>::show() const {
	for (int i = 0; i < len; i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << s_array[i];
	}
	std::cout << std::endl;
}

template <class T>
void Vector<T>::debug() const {
	for (int i = 0; i < cap; i++) {
		if (i < len) {
			std::cout << "|" << s_array[i] << ": " << &s_array[i] << "|" << " ";
		} else {
			std::cout << "|" << "|" << " ";
		}
	}
	std::cout << std::endl;
}

template <class T>
int Vector<T>::find(T data) const {
	for (int i = 0; i < len; i++) {
		if (s_array[i] == data) {
			return i;
		}
	}
	return -1;
}

template <class T>
bool Vector<T>::removeValue(T data) {
	int idx = find(data);
	if (idx == -1) {
		return false;
	}
	remove(idx);
	return true;
}

template <class T>
T Vector<T>::get(int idx) const {
	if (idx >= len || idx < 0) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	return s_array[idx];
}

template <class T>
T Vector<T>::pop() {
	if (isEmpty()) {
		throw std::runtime_error("Cannot pop from an empty vector");
	}
	
	T data = s_array[len - 1];
	len--;
	
	if (len > 0 && len <= cap / DECAY_FACTOR) {
		decay();
	}
	
	return data;
}

template <class T>
T Vector<T>::remove(int idx) {
	if (idx >= len || idx < 0) {
		throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds");
	}
	
	T data = s_array[idx];
	for (int i = idx; i < len - 1; i++) {
		s_array[i] = s_array[i + 1];
	}
	len--;
	
	if (len > 0 && len <= cap / DECAY_FACTOR) {
		decay();
	}
	
	return data;
}

template <class T>
Vector<int>* Vector<T>::findAll(T data) const {
	Vector<int>* result = new Vector<int>();
	for (int i = 0; i < len; i++) {
		if (s_array[i] == data) {
			result->push(i);
		}
	}
	return result;
}