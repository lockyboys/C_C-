/*
    하노이탑을 구하는 프로그램을 재귀 함수 이용하여 만들어 봅시다
    초기작업
    조건검사 <- 한단계 작응 문제 규정
    조건검사 <- 최소항의 문제 규정

*/

#include <stdio.h>

int factorial(int n) {
    int fact;
    if (n == 1){
        return 1;
    }
    
    fact = factorial(n-1);
    return fact * n;
}

void main() {

    printf("%d\n", factorial(3));

}