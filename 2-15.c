#include <stdio.h>

void increment(int *n) {
    *n = *n + 1;
}

void main () {

    int num = 10;
    printf("num=%d\n", num);
    increment(&num);
    printf("num=%d\n", num);
}