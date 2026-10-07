#include <stdio.h>
#include "custom.h"

void fx(){
    char a;
    if((a = getchar()) != '\n')
        fx();
    
    if(a != '\n')
        putchar(a);
    
}
int main(int argc, char *argv[]){
    fx();
    return 0;
}

