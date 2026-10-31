#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fx(){
    char a;

    if ((a= getchar()) != '\n'){
        fx();
    }
    if(a != '\n'){
        putchar(a);
    }
}
int main(void)
{   
   fx();
    return 0;
}
