
#include <stdio.h>
#include <string.h>
#define STR_COUNT       4

void main(){
    /*
    int strs[STR_COUNT][20] = { 0 };

    int  i, maxi = 0;
    int  size;

    printf("정렬할 문자열 %d개: \n", STR_COUNT);
    for (i = 0; i < STR_COUNT; i++)
        scanf("%s", strs[i]);

    for (i = 1; i < STR_COUNT; i++){
        if (strcmp(strs[maxi], strs[i]) < 0)
            maxi = i;
    }*/
    char strs[STR_COUNT][20];  // char로 수정

    int i, maxi = 0;

    printf("정렬할 문자열 %d개:\n", STR_COUNT);

    for (i = 0; i < STR_COUNT; i++)
        scanf("%19s", strs[i]);  // 버퍼 오버플로우 방지
    
    for (i = 1; i < STR_COUNT; i++) {
        if (strcmp(strs[maxi], strs[i]) < 0)
            maxi = i;
    }


   // if (strcmp(strs[maxi], strs[1]) < 0)
   //     maxi = 1;
   // if (strcmp(strs[maxi], strs[2]) < 0)
   //     maxi = 2;
   
    printf("가장 큰 문자열:%s\n", strs[maxi]);
}
/*
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

#define STR_COUNT 3

int main() {
    char strs[STR_COUNT][20];  // char로 수정

    int i, maxi = 0;

    printf("정렬할 문자열 %d개:\n", STR_COUNT);

    for (i = 0; i < STR_COUNT; i++)
        scanf("%19s", strs[i]);  // 버퍼 오버플로우 방지

    for (i = 1; i < STR_COUNT; i++) {
        if (strcmp(strs[maxi], strs[i]) < 0)
            maxi = i;
    }

    printf("가장 큰 문자열: %s\n", strs[maxi]);

    return 0;
}
*/