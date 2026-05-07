/*#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;   // �迭 �̸� = ù ��° ��� �ּ�

    printf("%d\n", arr[0]);
    printf("%d\n", *(p + 0));

    printf("%d\n", arr[1]);
    printf("%d\n", *(p + 1));

    return 0;
}*/
#include <stdio.h>

void change(int x) {
    x = 100;
}

int main() {
    int num = 10;
    change(num);

    printf("%d\n", num); // ������ 10
}
