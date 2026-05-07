#include <stdio.h>

int IsPrime(int n){
/*
소수인지를 판정하는 함수
*/
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    } 
    return 1;   
}

void main() {
    int num, i;

    for (num = 50; num <= 100; num++){
        if (IsPrime(num) == 1)
            printf("%d\n", num);
    }
}