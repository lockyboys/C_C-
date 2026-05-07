/*
    극장 예매 할잉 좌석 적용
    //2가지 방법을 섞어 사용하면 관리 편의성이 떨어집니다.
    1. 배열 사용방법
    #define TESTCASE    50000000
    int count[ARR_SiZE] = {0};
    2. 배열 사용방법
    int discount[] = {1, 3, 5, 7, 34};
    int count = sizeof(discount) / sizeof(discount[0]);
*/
#include <stdio.h>

void main(){
    int discount[] = {1, 3, 5, 7, 34};
    int count = sizeof(discount) / sizeof(discount[0]);
    int num, i;

    printf("예매할 좌석(1~34): ");
    scanf("%d", &num);

    for (i = 0; i < count; i++){
        if (discount[i] == num)
            break;
    }
    if (i < count)
        printf("할인가 적용\n");
    else
        printf("정상가 적용\n");
}