#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct {
   int* data; //Integer array
   size_t capacity;
   //size_t count; --> for dynamic arrays
} Array;

Array* arrayConstructor(size_t arraySize){
    // Struct allocation: 
    Array* arr =(Array*) calloc( 1, sizeof(Array));
    if (arr == NULL){
        return NULL;
    }
    arr->capacity = arraySize;
    arr->data = (int*) calloc(arraySize, sizeof(int));
    if (arr->data == NULL){
        free(arr);
        return NULL;
    }
    return arr;
}

void arrayDestructor(Array* array){
    free(array->data);
    free(array);
}

int* getData(Array* array, int index){
    if(index<array->capacity && index>=0){
        return (array->data + index);
    } 
    return NULL;
}

int main() {
    // Example
    Array* myArray = arrayConstructor(10);
    *getData(myArray, 0) = 5;
    printf("%i", *getData(myArray, 0));
    arrayDestructor(myArray);
}

/*
TODO
- Array dinâmico
- Escolher tipo do dado
- Setter
*/