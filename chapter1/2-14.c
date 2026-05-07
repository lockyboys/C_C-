#include <stdio.h>

int add(int x, int y);

void main() {
    /*
    int num = add(3, 5);

    printf("%d\n", num);
    */
   printf("%d\n", add(3, 5));
}

int add(int x, int y){
    /*
    int sum = x + y;
    
    return sum;
    */
   return x + y;
}