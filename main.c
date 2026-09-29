#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int a = 10;
    int b = 4;

    printf("%d", sizeof(a++));
    printf("%d", a);

    return EXIT_SUCCESS;
}
