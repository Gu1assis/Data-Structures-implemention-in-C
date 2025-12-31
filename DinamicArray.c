#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    void *data;
    size_t elementSize;
    size_t size;
    size_t maxSize;
} DinamicArray;

DinamicArray *dinamicArrayConstructor(size_t elementSize, size_t initialMaxSize){
    if(initialMaxSize == 0 || elementSize == 0){
        fprintf(stderr, "InitialSize or ElementSize can't be zero");
        return NULL;
    }
    DinamicArray *arr = calloc(1, sizeof(DinamicArray));
    if (arr == NULL){
        return NULL;
    }
    arr->elementSize = elementSize;
    arr->maxSize = initialMaxSize;
    arr->size = 0;
    arr->data = (void*) calloc(initialMaxSize, elementSize);
    if (arr->data == NULL){
        free(arr);
        return NULL;
    }
    return arr;
}

void* getData(DinamicArray *arr, int index){
    if(arr != NULL && index< arr->size && index >=0){
        return ((char*)arr->data + arr->elementSize*index);
    }
    return NULL;
}

void add(DinamicArray *arr, void *data){
    if(arr->size >= arr->maxSize){
        void* temp_arr = realloc(arr->data, (arr->maxSize*2)*arr->elementSize);
        if(temp_arr == NULL){
            perror("Reallocation failed, original memory preserved");
            return;
        }else {
            arr->data = temp_arr;
            arr->maxSize = arr->maxSize*2;
        }
    }
    void *destination = (char*)arr->data + (arr->size * arr->elementSize);
    memcpy(destination, data,  arr->elementSize);
    arr->size+=1;
}

void removeByIndex(DinamicArray *arr, int index){
    if(arr==NULL || index > arr->size || index < 0){
        return;
    }
    if(index + 1 < arr->size){
        memmove(getData(arr,index), getData(arr, index+1), arr->elementSize*(arr->size - (index+1)));
    } 
    arr->size--;
}

void change(DinamicArray *arr, void *data, int index){
    if(index < arr->size && index>=0){
        memcpy(getData(arr, index), data, arr->elementSize);
    } else {
        return;
    }
}

void shrinkToFit(DinamicArray *arr){
    if(arr == NULL || arr->size == arr->maxSize) return;
    size_t newMax = arr->size > 0 ? arr->size : 1;
    void *temp = realloc(arr->data, newMax);
    if( temp != NULL){
        arr->data = temp;
        arr->maxSize = newMax;
    } 
}

void dinamicArrayDestructor(DinamicArray *arr){
    if(arr == NULL){return;}
    free(arr->data);
    free(arr);
}

int main(){
    size_t maxSize = 10;
    DinamicArray *myArray = dinamicArrayConstructor(sizeof(int), maxSize);
    if(myArray == NULL){
        fprintf(stderr, "Cannot create Dinamic Array.");
        return 1;
    }
    // add data:
    srand(time(NULL));
    for(int i=0; i < myArray->maxSize; i++){
        int data = rand();
        add(myArray, &data);
    }

    //Visualization:
    printf("\nCreated a Dinamic Array:\n");
    for(int i=0; i < myArray->maxSize; i++){
        void *ptr = getData(myArray,i);
        if(ptr == NULL){
            printf("Error: Cannot retrieve data");
        }
        printf("%d index: %d\n", i, *(int*)ptr);
    }
    // Removing first 5 itens:
    for(int i=0; i < myArray->maxSize - 5; i++){
        removeByIndex(myArray, 0);
    }
    shrinkToFit(myArray);

    //Visualization after removal:
    printf("\nAfter Removal:\n");
    for(int i=0; i < myArray->maxSize; i++){
        void *ptr = getData(myArray,i);
        if(ptr == NULL){
            printf("Error: Cannot retrieve data");
        }
        printf("%d index: %d\n", i, *(int*)ptr);
    }
    dinamicArrayDestructor(myArray);
    printf("\n");
    return 0;
}
