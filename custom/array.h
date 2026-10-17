#include <stdio.h>
#include <stdlib.h>
/*
 * array.h
 *
 * A small dynamically allocated integer array with function-pointer
 * operations for appending and printing values.
 *
 * Usage:
 *     array *arr = createArray(4);
 *     if (arr == NULL) {
 *         return 1;
 *     }
 *
 *     arr->append(arr, 10);
 *     arr->print(arr);
 *
 *     free(arr->ptr);
 *     free(arr);
 *
 * createArray allocates both the array object and its integer storage.
 * The caller owns both allocations and must release them when finished.
 */
typedef struct array array;

/**
 * Represents a dynamically allocated array of integers.
 *
 * The operation pointers are initialized by createArray. Callers do not
 * need to assign append or print manually.
 */
struct array {
    /** Maximum number of integers the array can hold. */
    int capacity;

    /** Index of the most recently stored value, or -1 when empty. */
    int lastIndex;

    /** Number of integers currently stored in the array. */
    int size;

    /** Dynamically allocated storage for the integer values. */
    int *ptr;

    /** Prints all stored values separated by spaces. */
    void (*print)(array *);

    /** Adds a value unless the array has reached its capacity. */
    void (*append)(array *, int);
};

/**
 * Creates an integer array with the requested capacity.
 *
 * @param capacity Maximum number of values the array can store.
 * @return A newly allocated array, or NULL if allocation fails.
 *
 * The returned object owns its storage. Release it with:
 *
 *     free(arr->ptr);
 *     free(arr);
 */
array* createArray(int capacity);

/** Appends val to arr when arr has available capacity. */
void append(array *arr, int val);

/** Prints every value currently stored in arr. */
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
