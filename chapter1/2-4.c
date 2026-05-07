/*
    rand 함수 기능 테스트
    //2가지 방법을 섞어 사용하면 관리 편의성이 떨어집니다.
    1. 배열 사용방법
    #define TESTCASE    50000000
    int count[ARR_SiZE] = {0};
    2. 배열 사용방법
    int discount[] = {1, 3, 5, 7, 34};
    int count = sizeof(discount) / sizeof(discount[0]);
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SiZE    10
#define TESTCASE    50000000

void main() {
    int num, i;
    int count[ARR_SiZE] = {0};

    srand(time(NULL));

    // 100번 반복
    for (i = 0; i < TESTCASE; i++) {
        num = (rand() % ARR_SiZE) + 1;  // 1~10
        count[num - 1]++;
    }

    // 결과 출력
    for (i = 0; i < ARR_SiZE; i++) {
        printf("%2d : 횟수=%3d 비율=%3d%%\n",
               i + 1,
               count[i],
               (int)(count[i] * 100.0 / TESTCASE + 0.5));
    }

}