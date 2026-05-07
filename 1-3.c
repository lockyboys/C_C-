/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr;

    arr = (int *)malloc(sizeof(int) * n);

    // 값 저장
    for(int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    // 출력
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);  // 반드시 해제!

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr;

    arr = (int *)malloc(sizeof(int) * n);

    // 메모리 할당 확인 (중요!)
    if (arr == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    // 값 저장
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    // 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);  // 반드시 해제!

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr;
    int i;   // ?? 여기서 미리 선언

    arr = (int *)malloc(sizeof(int) * n);

    if (arr == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    // 값 저장
    for (i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    // 출력
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
