#include <stdio.h>

int gateStaticTrap(int n)
{
    int d = 0; // Initialized ONLY ONCE in the Data Segment
    d = d + 1;
    if (n <= 1)
        return 1;

    // Warning: d is modified inside the recursive call!
    return gateStaticTrap(n - 1) + d;
}

int main()
{
    printf("%d\n", gateStaticTrap(4));
    return 0;
}