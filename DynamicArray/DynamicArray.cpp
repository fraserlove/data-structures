#include <iostream>

#include "DynamicArray.h"

template <class T>
DynamicArray<T>::DynamicArray() {
	len = 0;
	cap = MIN_CAPACITY;
	s_array = new T[cap];
}

template <class T>
DynamicArray<T>::DynamicArray(int size) {
	len = cap = 0;
	if (size < 1) {
		std::cout << "ERROR: Illegal capacity " << size << " entered" << std::endl;
	}
	else {
		cap = size;
		s_array = new T[cap];
	}
}

template <class T>
DynamicArray<T>::DynamicArray(T data[], int size) {
	len = 0;
	cap = size;
	s_array = new T[cap];
	Push(data, size);
}

template <class T>
DynamicArray<T>::~DynamicArray() {
	len = 0;
	delete[] s_array;
}

template <class T>
void DynamicArray<T>::Set(int idx, T data) {
	if (idx < len && idx >= 0) {
		s_array[idx] = data;
	}
	else {
		std::cout << "ERROR: Index " << idx << " outwith array bounds" << std::endl;
	}
}

template <class T>
void DynamicArray<T>::Push(T data) {
	if (len + 1 >= cap) {
		cap *= GROWTH_FACTOR;
		T* new_array = new T[cap];
		for (int i = 0; i < len; i++) {
			new_array[i] = s_array[i];
		}
		T* temp = s_array;
		s_array = new_array;
		delete[] temp;
	}
	s_array[len++] = data;
}

template <class T>
void DynamicArray<T>::Push(T data[], int size) {
	for (int i = 0; i < size; i++) {
		Push(data[i]);
	}
}

template <class T>
void DynamicArray<T>::Insert(int idx, T data) {
	if (idx < len + 1 && idx >= 0) {
		if (len + 1 >= cap) {
			cap *= GROWTH_FACTOR;
		}
		T* new_array = new T[cap];
		for (int i = 0, j = 0; i < len + 1; i++, j++) {
			new_array[i] = s_array[j];
			if (i == idx) {
				new_array[i] = data;
				j--;
			}
		}
		T* temp = s_array;
		s_array = new_array;
		delete[] temp;
		len++;
	}
	else {
		std::cout << "ERROR: Index " << idx << " outwith array bounds" << std::endl;
	}
}

template <class T>
void DynamicArray<T>::Insert(int idx, T data[], int size) {
	if (idx >= len) {
		std::cout << "ERROR: Index " << idx << " outwith array bounds" << std::endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			Insert(idx + i, data[i]);
		}
	}
}

template <class T>
void DynamicArray<T>::Clear() {
	len = 0;
	cap = MIN_CAPACITY;
	T* new_array = new T[cap];
	T* temp = s_array;
	s_array = new_array;
	delete temp;
}

template <class T>
void DynamicArray<T>::Reverse() {
	T* new_array = new T[cap];
	for (int i = 0; i < len; i++) {
		new_array[i] = s_array[len-i-1];
	}
	T* temp = s_array;
	s_array = new_array;
	delete[] temp;
}

template <class T>
void DynamicArray<T>::Show() {
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			std::cout << s_array[i];
		}
		else {
			std::cout << ", " << s_array[i];
		}
	}
	std::cout << std::endl;
}

template <class T>
void DynamicArray<T>::ShowAsString() {
	for (int i = 0; i < len; i++) {
		std::cout << s_array[i];
	}
	std::cout << std::endl;
}

template <class T>
void DynamicArray<T>::ShowDebug() {
	for (int i = 0; i < cap; i++) {
		if (i == 0) {
			std::cout << "(" << i << ": " << s_array[i] << ")";
		}
		else {
			if (i == len) {
				std::cout << " | (";
				std::cout << i << ": " << s_array[i] << ")";
			}
			else {
				std::cout << ", (" << i << ": " << s_array[i] << ")";
			}
		}
	}
	std::cout << std::endl;
}

template <class T>
int DynamicArray<T>::Length() { return len; }

template <class T>
int DynamicArray<T>::Find(T data) {
	for (int i = 0; i < len; i++) {
		if (s_array[i] == data) {
			return i;
		}
	}
	return -1;
}

template <class T>
bool DynamicArray<T>::IsEmpty() { return Length() == 0; }

template <class T>
bool DynamicArray<T>::RemoveValue(T data) {
	for (int i = 0; i < len; i++) {
		if (s_array[i] == data) {
			Remove(i);
			return true;
		}
	}
	return false;
}

template <class T>
bool DynamicArray<T>::Contains(T data) { return Find(data) != -1; }

template <class T>
T DynamicArray<T>::Access(int idx) { 
	if (idx < len && idx >= 0) {
		return s_array[idx];
	}
	else {
		std::cout << "ERROR: Index " << idx << " outwith array bounds" << std::endl;
	}
}

template <class T>
T DynamicArray<T>::Pop() {
	if (IsEmpty()) {
		std::cout << "ERROR: Dynamic array is empty" << std::endl;
	}
	else {
		if ((len - 1) < (cap / DECAY_FACTOR)) {
			cap /= DECAY_FACTOR;
			T* new_array = new T[cap];
			for (int i = 0; i < len; i++) {
				new_array[i] = s_array[i];
			}
			T* temp = s_array;
			s_array = new_array;
			delete[] temp;
		}
		len--;
		return s_array[len];
	}
}

template <class T>
T DynamicArray<T>::Remove(int idx) {
	if (idx < len && idx >= 0) {
		T data = s_array[idx];
		if ((len - 1) < (cap / DECAY_FACTOR)) {
			cap /= DECAY_FACTOR;
		}
		T* new_array = new T[cap];
		for (int i = 0, j = 0; i < len; i++, j++) {
			if (i == idx) {
				j--;
			}
			else {
				new_array[j] = s_array[i];
			}
		}
		T* temp = s_array;
		s_array = new_array;
		delete[] temp;
		len--;
		return data;
	}
	else {
		std::cout << "ERROR: Index " << idx << " outwith array bounds" << std::endl;
	}
}

template <class T>
DynamicArray<int>* DynamicArray<T>::FindAll(T data) {
	DynamicArray<int>* indices = new DynamicArray<int>();
	for (int i = 0; i < len; i++) {
		if (s_array[i] == data) {
			indices->Push(i);
		}
	}
	return indices;
}