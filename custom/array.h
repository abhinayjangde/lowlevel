#include <stdio.h>
#include <stdlib.h>

typedef struct array array;

struct array {
    int capacity;
    int lastIndex;
    int size;
    int *ptr;

    void (*print)(array *);
    void (*append)(array *, int);
};

void append(array *arr, int val);
void print(array *self);

array* createArray(int capacity){
    array *arr = (array*)malloc(sizeof(array));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    arr->capacity = capacity;
    arr->lastIndex = -1;
    arr->size = 0;
    arr->ptr = (int*)malloc(capacity * sizeof(int));
    if (arr->ptr == NULL) {
        free(arr);
        printf("Memory allocation failed!\n");
        return NULL;
    }

    arr->print = print;
    arr->append = append;
    return arr;
}
void append(array *arr, int val){
    if(arr->size >= arr->capacity){
        printf("array is full\n");
        return;
    }
    arr->lastIndex+=1;
    arr->size+=1;
    arr->ptr[arr->lastIndex] = val;
}

void print(array * self){
    for(int i=0; i<=self->lastIndex; i++){
        printf("%d ", self->ptr[i]);
    }
}
