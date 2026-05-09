/*
      할당 -> 해제
    힙 영역의 주소를 가진 포인터 변수
    스택 영역 
    테이터 영역
    장점 : 스택보다 큰 변수를 할당 가늘
          실행시간에 크기를 정할 수 있다
    단점 : 할당/해제의 책임이 프로그래머에게 있다

*/

#include <stdio.h>
#include <malloc.h>

void main() {
    int* pInum = NULL;

    pInum = (int*) malloc(sizeof(int));
    *pInum = 10;
    printf("*plnum=%d\n", *pInum);
    *pInum = *pInum + 1;
    printf("*plnum = %d\n", *pInum);
    free(pInum);
}