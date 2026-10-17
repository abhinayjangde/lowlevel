#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    int capacity;
    int size;
    int *arr;
} array;

array * createArray( int capacity){
    array * arr = (array*)malloc(sizeof(array));

    (*arr).capacity = capacity;
    (*arr).size = 0;
    (*arr).arr = (int*)malloc(capacity * sizeof(int));
    return arr;
}

void append(array *arr, int val){
    // checking if array is full
    if(arr->size >= arr->capacity){
        printf("array capacity is full\n");
        return;
    }

    // if space available then insert new element
    arr->arr[arr->size] = val;
    arr->size += 1;
}

void appendAt(array *arr, int index, int val){}

int get(array *arr, int index){
    if(arr->size == 0){
        printf("array is empty\n");
        return -1;
    }
    if(index < 0 || index > arr->size){
        printf("invalid index\n");
        return -1;
    }
    return arr->arr[index];
}

void print(array *arr){
    for(size_t i=0; i<arr->size; i++){
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}


void delete(array *arr, int index){
    if(index < 0 || index > arr->size){
        printf("Invalid index\n");
        return;
    }
    if(arr->size == 0 && arr->capacity == 0){
        printf("array is empty\n");
        return;
    }
    for(size_t i=index; i<arr->size-1; i++){
        arr->arr[i] = arr->arr[i+1];
    }
    arr->size -=1;
}
int main(void)
{      
    array *marks = createArray(6);
    append(marks, 4);
    append(marks, 2);
    append(marks, 9);
    append(marks, 79);
    append(marks, 7);
    append(marks, 60);
    

    // int index = 3;
    // int val = get(marks,index);
    // printf("value at %d index is %d\n",index, val);

    delete(marks,1);

    print(marks);
    // printf("size: %d\n", marks->size);
    // printf("capacity: %d\n", marks->capacity);
    return 0;
}
