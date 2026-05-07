/*
    문자열 기초 "Hi!12" 문자열을 %s %c %x로 출력해 보자!!
*/
#include <stdio.h>
#include <string.h>

void main(){
    //char str[]="Hi!12";
    //char str[] = {'H', 'i', '!', '1', '2' ,'\0'};
    char str[] = {0x48, 0x69, 0x21, 0x31, 0x32, 0x00};
    int i;

    printf("%s\n", str);

    for (i = 0; i < strlen(str); i++)
        printf("%c", str[i]);

    printf("\n");

    for (i = 0; i < strlen(str); i++)
        printf("%02x ", str[i]);
    printf("\n");

    printf("sizeof=%d strlen=%d\n", 
        sizeof(str),strlen(str));

}