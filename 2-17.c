#include <stdio.h>

void PrintHello(int count) {
    if (count == 0){
        return ;
    }
    
    printf("Hello\n");
    PrintHello(count-1);
}

void main() {
    int num, i;

    PrintHello(3);
}