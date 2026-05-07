/*
양의 정수를 입력 받아 각 자리의 수를 거꾸로 출력
*/
#include <stdio.h>

void main(){
    int num, index = 0, i;
    int arr[10];

    printf("양의 정수 : ");
    scanf("%d", &num);

    while(num > 0){
        arr[index] = num % 10;
        num = num / 10;
        index++;
    }
    for(i = 0; i < index; i++)
        printf("%d", arr[i]);
}