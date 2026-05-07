/*
    주소연자자와 문자열
    연월일 입려규받아 연, 월, 일로 분할
*/
#include <stdio.h>
#include <string.h>

void main(){
    
    char buffer[100];
    int pos[3] = { 0 };
    int  i, idxPos = 1;

    printf("연월일(year/month/day)\n: ");
    scanf("%s", buffer);

    i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '/') {
            buffer[i] = '\0';
            pos[idxPos] = ++i;
            idxPos++;
        }
        i++;
    }
   /*   for ( i = 0; i < idxPos; i++) {
        printf("%d",pos[i]);
    }*/
    printf("연=%s 월=%s 일=%s\n", 
        &buffer[pos[0]], &buffer[pos[1]], &buffer[pos[2]]);
    printf("연=%s 월=%s 일=%s\n", 
        buffer + pos[0], buffer + pos[1], buffer + pos[2]);
}