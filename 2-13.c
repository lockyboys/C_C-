#include <stdio.h>

void PrintHello(int num){

    printf("안녕하세요\n %d번 고객님\n\n", num);

}

void PrintChar(char ch, int count) {

    for (int i = 0; i < count; i++)
        printf("%c", ch);
    printf("\n");
}


void main() {

    PrintHello(10);
    PrintHello(2);
    PrintHello(12);

    PrintChar('A', 10);
    PrintChar('B', 20);

}