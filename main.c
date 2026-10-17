#include <stdio.h>
#include <stdlib.h>
#include "custom/array.h"

int main(void)
{      
    array *arr = createArray(4);
    
    arr->append(arr, 34);
    arr->append(arr, 3);
    arr->append(arr, 9);
   
    arr->print(arr);

    free(arr->ptr);
    free(arr);
    return 0;
}