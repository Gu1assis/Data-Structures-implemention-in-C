#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct {
   int* data; //Integer array
   size_t capacity;
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

int* getArrayData(Array* array, int index){
    if(index<array->capacity && index>=0){
        return (array->data + index);
    } 
    return NULL;
}

int* setArrayData(Array* array, int index, int data){
    *getArrayData(array, index) = data;
}

int main() {
    // Constructor:
    Array* myArray = arrayConstructor(10);
    //Set:
    setArrayData(myArray, 0, 5);
    //View Results:
    printf("%i", *getArrayData(myArray, 0));
    //Free memory:
    arrayDestructor(myArray);
}
