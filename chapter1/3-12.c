/*

    문자열 표현방법 2가지 
    

*/
#include <stdio.h>
#define MAX_DIGIT   4

void main() {
    //char strName1[20] = "English";
    char *strUnits[] = {"", "십", "백", "천"};
    char *strDigits[] = {"영", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
    int num, digitnum[MAX_DIGIT];
    int digits, i;
    
    printf("%d자리 이내의 숫자: ", MAX_DIGIT);
    scanf("%d", &num);

    digits = 0;
    while (num > 0) {
        digitnum[digits++] = num % 10;
        num /= 10;
    }
    for (i = digits - 1; i >= 0; i--) {
        if (digitnum[i] == 0)
            continue;
        printf("%s%s ", (digitnum[i] == 1 && i > 0) ? "" : strDigits[digitnum[i]], strUnits[i]);
    }
}