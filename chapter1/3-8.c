/*

    배열이름
        - 배열을 대표하는 역활 + 포인터 역활
        - 다른 변수에 대입할때는 항상 포인터로 간주됨

*/
#include <stdio.h>

void main() {
    char butter[100];
    char butter2[100];
    char* ptr;
    printf("정렬할 두 수 입력: ");
    scanf("%s", &butter);
    printf("%s\n", butter);
    ptr = butter;
    printf("%s\n", ptr);
}