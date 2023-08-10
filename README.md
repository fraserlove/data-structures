# Data Structures
A data structures library implemented in C++ that features commonly found structures such as queues, stacks, singly linked lists and dynamic arrays. The library has been designed so that the data structures are independent of any c++ standard or third-party library. Data structures have been designed to build upon previous structures, for example the priority queue is implemented using the library's own dynamic array class. 

The time complexities of each structure's operations are included alongside the method’s declaration in the structures header class. Within each data structures folder is a Main.cpp file which is not a dependency to create the data structure but provides a console system to easily create and modify the relevant data structure for testing.

## Included Data Structures
Some data structures are built ontop of existing data structures in the library. This relationship is highlighed by including the underlying data structure used in parenthesis.
  - Singly Linked List
  - Dynamic Array <i>(static arrays)</i>
  - Stack <i>(singly linked list)</i>
  - Queue <i>(singly linked list)</i>
  - Priority Queue <i>(dynamic array - represents binary heaps)</i>

## Example Makefile for Debugging
This is an example makefile for debugging the Priority Queue. Place the following makefile, alongside all `.cpp` and `.h` dependencies.
```
CC = g++

PriorityQueue: DynamicArray.o PriorityQueue.o Main.o
	$(CC) -o PriorityQueue DynamicArray.o PriorityQueue.o Main.o
	$(RM) *.o

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	$(CC) -c DynamicArray.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	$(CC) -c PriorityQueue.cpp

Main.o: Main.cpp PriorityQueue.h
	$(CC) -c Main.cpp

clean:
	$(RM) PriorityQueue *.o *-
```
