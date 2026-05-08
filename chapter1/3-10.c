/*

    배열이름을 함수인자로 줄 때
    ● 인자 표현 방법에 상관없이 포인터로서 전달됨
        - 많은 양의 데이터가 봇사되는 것을 방지해 줌
        - 메모리가 공유됨을 알고 이용하자!
    ● 포인터와 원소갯수로 전달!

*/
#include <stdio.h>

int GetAverage(int *scores, int count) {
    int sum = 0, i;
    printf("GetAverage: sizeof(scores)=%d\n", sizeof(scores));
    for (i = 0; i < count; i++)
        sum += scores[i];
    return sum / count;
}
/*
int GetAverage(int scores[5]) {
    int sum = 0, i;
    printf("GetAverage: sizeof(scores)=%d\n", sizeof(scores));
    for (i = 0; i < 5; i++)
        sum += scores[i];
    return sum / 5;
}
*/
void main() {
    int scores[5] = { 78, 69, 100, 98, 82};
    printf("main: sizeof(scores)=%d\n", sizeof(scores));
    printf("GetAverage=%d\n", GetAverage(scores, sizeof(scores)/sizeof(scores[0])));
    /*printf("GetAverage=%d\n", GetAverage(scores));*/
}