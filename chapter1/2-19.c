#include <stdio.h>

void PrintHello444(int count) {
    if (count == 0){
        return ;
    }
    
    printf("Hello\n");
    PrintHello444(count-1);
}

void main() {
    int num, i;

    PrintHello444(3);
}