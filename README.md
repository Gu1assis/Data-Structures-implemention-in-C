# Data-Structures-implemention-in-C

Arrays, Linked Lists, Stacks, Queues, Hash Tables (Maps/Dictionaries), Trees, Heaps, and Graphs

## Arrays

My implementation focus on making a simple representation of an Array.

### Struct

The structure of the array is based on two parts:

```
int* data;
```
This stores a pointer to a sequence of integers. A pointer was created because if we assigned just a simple integer with int data; it wasn't be possible to have more than one integer in the array. 

```
size_t capacity;
```

This variable stores size of the array using the size_t data type.

