#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int list(){
    system("touch hello.txt && ls -l > hello.txt");
    return 0;
}

int main(void)
{   
    list();
    return 0;
}
