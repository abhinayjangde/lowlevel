#include <stdio.h>
#include "custom.h"

int main(int argc, char *argv[]){
    int nums[] = {1,2,3,4,5,6,7};
    // print even numbers only
    for(int i=0; i<7; i++){
        if(!(nums[i] & 1)){
            printf("%d\n", nums[i]);
        }
    }
    return 0;
}

