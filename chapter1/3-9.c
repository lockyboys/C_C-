/*

    배열이름
        - 배열을 대표하는 역활 + 포인터 역활
        - 다른 변수에 대입할때는 항상 포인터로 간주됨

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