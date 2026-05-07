/*
    문자열 입력 받기
*/
#include <stdio.h>
#include <string.h>

void main(){
    
    char buffer[100];
    int  num;

    printf("문자열");
    scanf("%s", buffer);
    //scanf("%d", &num);

    printf("%s", buffer);
}