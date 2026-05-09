/*
    함수 포인터의 활용/ 이보다 멋진 함수는 없다!!!! | 다채로운 함수 포인터!!!!
*/
#include <stdio.h>

int isOdd(int value) {  //홀수
    if (value % 2 == 1)
        return 1;
    return 0;
}
int isEven(int value) { //짝수
    if (value % 2 == 0)
        return 1;
    return 0;
}
void showif(int *arr, int size, int (*pred)(int)){
    for (int i =0; i < size; i++)
        if (pred(arr[i]))
            printf((*pred == isOdd)? "짯수 = %d" :"홀수 = %d" , arr[i]);
    puts(" ");
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    showif(a, 10,isOdd);
    showif(a, 10,isEven);
    return 0;
}