#include <stdio.h>
#include "custom.h"

int main(int argc, char *argv[]){
    int num1 = 1;
    int num2 = 3;
    int sum;
    __asm__(
        "addl %%ebx, %%eax;"
        : "=a" (sum)
        : "a" (num1), "b" (num2)
    );
    printf("%d",sum);
    return 0;
}

