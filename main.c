#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

    puts(fork() == 0);

    return 0;
}