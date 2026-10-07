#include <stdio.h>

static inline int max(int a, int b){
    return (a>b) ? a : b;
}

static inline int factorial(int n){
    return n == 0 ? 1 : n * factorial(n-1);
}

 
