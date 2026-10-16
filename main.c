#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[8];

    strcpy(buffer, "ABCDEFGHIJKLMN");

    printf("%s\n", buffer);
    return 0;
}