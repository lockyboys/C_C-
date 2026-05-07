/*
    문자열 관련 함수 사용 예
    

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    
    char str[100];
    int amount = 0, newAmount = 0;
    int  i, idxPos = 1;

    

    i = 0;
    while (1) {
        printf("\n잔고=%d원\n", amount);
        printf("입금/출금 000원( 종료=Enter)\n: ");
        gets(str);//scanf("%s", str);
        if (strlen(str) == 0)
            break;
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == ' ') {
                str[i] ='\0';
                newAmount = atoi(&str[i + 1]);
                break;
            }
        }
        if (strcmp("입금", str) == 0)
            amount += newAmount;
        if (strcmp("출금", str) == 0)
            amount -= newAmount;
    }
}*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100];
    int amount = 0, newAmount = 0;
    int i;

    while (1) {
        printf("\n잔고=%d원\n", amount);
        printf("입금/출금 000원 (종료=Enter)\n: ");

        // gets 대신 fgets 사용
        if (fgets(str, sizeof(str), stdin) == NULL)
            break;

        // 개행 제거
        str[strcspn(str, "\n")] = '\0';

        if (strlen(str) == 0)
            break;

        // 금액 파싱
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == ' ') {
                str[i] = '\0';
                newAmount = atoi(&str[i + 1]);
                break;
            }
        }

        if (strcmp("입금", str) == 0)
            amount += newAmount;
        else if (strcmp("출금", str) == 0)
            amount -= newAmount;
        else
            printf("잘못된 입력입니다.\n");
    }

    printf("\n최종 잔고: %d원\n", amount);

    return 0;
}