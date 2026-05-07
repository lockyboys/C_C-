#include <stdio.h>

void PrintHello2(int count) {
    if (count == 0){
        return ;
    }
    
    printf("Hello\n");
    PrintHello2(count-1);
}

void main() {
    int num, i;

    PrintHello2(3);
}