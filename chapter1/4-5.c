/*
    
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int rad;
    int begin = 100, end = 300;

    srand((unsigned int)time(NULL));

    rad = rand() % (end - begin + 1) + begin;   //0 ~ 32767 RAND MAX

    printf("%d", rad);

    return 0;
}