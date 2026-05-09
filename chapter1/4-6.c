#include <stdio.h>
#include <stdlib.h>

int main() {

    // 처음 크기 3
    int* arr = (int*)malloc(sizeof(int) * 3);

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 5;

    // 크기 10으로 확장
    int* temp = (int*)realloc(arr, sizeof(int) * 10);

    if (arr == NULL) {
        printf("메모리 재할당 실패\n");
        free(arr);
        return 1;
    }
    arr = temp;

    arr[3] = 6;
    arr[4] = 7;
    arr[5] = 8;

    // 출력
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // 메모리 해제
    free(arr);

    return 0;
}