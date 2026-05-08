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
void SetMinMax(int *pMin, int *pMax) {
    if (*pMin > *pMax) {
        int temp = *pMin;
        *pMin = *pMax;
        *pMax = temp;
    }
}

int main() {
    int n1, n2;

    printf("정렬할 두 수 입력: ");
    scanf("%d%d", &n1, &n2);
    SetMinMax(&n1, &n2);
    printf("작은 수=%d 큰수=%d\n", n1, n2);

    return 0;
}