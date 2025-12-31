# Data Structures implemention in C

A simple project created by me to help learn C and Data structurse

List of desired implementations:

- Arrays; 
- Linked Lists; 
- Stacks;
- Queues; 
- Hash Tables (Maps/Dictionaries);
- Trees;
- Heaps;
- Graphs;

# Arrays

## Simple array

This is a fixed size and data type array. 

### Struct

The structure of the array is based on two parts:

- int* data;

This stores a pointer to a sequence of integers. A pointer was created because if we assigned just a simple integer with int data; it wasn't be possible to have more than one integer in the array. 

- size_t capacity;

This variable stores size of the array using the size_t data type.

## DinamicArray

This is similar to an ArrayList in java. It has dinamic size and can be defined using any data type.

### Struct

- void* data

Instead of int*, we use void*. The void pointer in C is a "wildcard" pointer that can point to any memory address, regardless of what is there.

- size_t elementSize

Since C will no longer know if we are storing an int, a double, or a struct, we need to manually save how many bytes each element occupies.

- size_t size 

Represents how many elements are currently occupying the array.

- size_t capacity: 

Represents how much total space has been allocated on the Heap.

***Using char as a unity of byte***

We cast the arr->data to char*, because char occupies exactly 1 byte of memory.