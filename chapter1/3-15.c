/*
    계좌관리 프로그렘 개요
    예금주의 입력을 받아 계좌를 개설하고 관리하는 프로그램을 작성 하시오.
    계좌별 계좌번호, 예금주명, 잔액을 유지하고 1. 계좌개설 2. 입금 3.출금의 3가지 작업을 수행하도록 한다.


        파일의 사용의 필요성과 파일 종류
    ● 파일의 필요성
        - 프로로그램이 종료되더라도 디스크에 내용을 남길 수 있다
    ● 파일의 두가지 종류
        - 텍스트 파일(*.txt)
            ．내용이 눈에 보이는 코드 영역의 문자 들로만 이루어진 파일
            ．테스트 편집기를 통하여 그 내용을 보고 수정 가능
        - 이진 파일(BINARY FILE)
            ．코드 영역의 제한 없이 모든 내용을 저장하는 파일(실행파일, 그림 파일, 음악 파일, 동영상 파일 등)
            ．전용 프로그램으로써 내용을 볼 수 있음

    파일위치(파일 경로)
    ● 절대 경로 
        -실해 위치와 상관없이 위치 지정 가능
         "드라이브명:\\디렉터리명1\\디렉터리명\\파일명.txt"
         "c:\\Temp\\myfile.txt"
    ● 상대 경로
        - 경로 표시 헚이 파일 이름만 제골("myfile.txt")
        - 현재 프로그램이 수행되고 있는 위치에서 찾음
    fopen(() -> read/write -> fclose()
 1회(열기모드적용)   N회         1회
                fprintf/fscanf  (텍스트 파일용)
                fwrite/fread    (이진파일용)
                fputs/fgets     (텍스트 파일용)
   파일 열기 모드           문자열
   w  b                    "wb"
   a+ t                    "r+b"
   r                       "a+b

 */
/*  
#include <stdio.h>
#include <string.h>
#define MAX_ACCOUNT   3
typedef struct {    // typedef struct _StUDENT { 
    int id;         // 꼐좌명
    char name[20];  //예금주명
    int balance;    //잔액
} ACCOUNT;
//typedef struct _StUDENT StUDENT;
void PrintAll(ACCOUNT *accounts, int cntAccount) {
    printf("---------------------\n");
    printf("계좌번호    예금주    잔액\n");
    for (int i = 0; i < cntAccount; i++) 
        printf("%8d %8s %8d", accounts[i].id, accounts[i].name, accounts[i].balance);
    printf("---------------------\n");
}

ACCOUNT *SearchAccount(ACCOUNT* accounts, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].id == id)
            return &accounts[i];
    }
    return NULL;
}

void main() {
    ACCOUNT accounts[MAX_ACCOUNT];
    int cntAccount = 0, menu;
    while (1) {
        PrintAll(accounts, cntAccount);
        printf("계좌개설(1 입금(2) 출금(3) 종료90)\n: ");
        scanf("%d", &menu);
        if (menu == 1) { //계좌개설
            int id;
            char name[20];
            ACCOUNT* pSearch;

            if (cntAccount == MAX_ACCOUNT) {
                printf("계좌를 추가할 수 없습니다");
                continue;
            }
            printf("계좌번호: "); scanf("%d", &id);
            pSearch = SearchAccount(accounts,cntAccount, id);
            if (pSearch != NULL) {
                printf("이미 있는 계좌번호입니다\n");
                continue;
            }
            printf("예금주: "); scanf("%s", name);
            accounts[cntAccount].id = id;
            strcpy(accounts[cntAccount].name, name);
            accounts[cntAccount].balance = 0;
            cntAccount++; 
        }
        else if (menu == 2 ) {  //입금


        }
        else if (menu == 3 ) {  //출금

        }
        else if (menu == 0 )    //종료
            break;

    }
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNT 3

typedef struct {
    int id;             // 계좌번호
    char name[20];      // 예금주명
    int balance;        // 잔액
} ACCOUNT;


// 전체 계좌 출력
void PrintAll(ACCOUNT *accounts, int cntAccount) {

    printf("\n-----------------------------\n");
    printf(" 계좌번호    예금주      잔액\n");
    printf("-----------------------------\n");

    for (int i = 0; i < cntAccount; i++) {

        printf("%8d %10s %10d\n",
            accounts[i].id,
            accounts[i].name,
            accounts[i].balance);
    }

    printf("-----------------------------\n");
}


// 계좌 검색
ACCOUNT* SearchAccount(ACCOUNT* accounts, int count, int id) {

    for (int i = 0; i < count; i++) {

        if (accounts[i].id == id)
            return &accounts[i];
    }

    return NULL;
}


int main(void) {

    ACCOUNT accounts[MAX_ACCOUNT] = {0};

    int cntAccount = 0;
    int menu;

    while (1) {

        PrintAll(accounts, cntAccount);

        printf("\n계좌개설(1) 입금(2) 출금(3) 종료(0)\n");
        printf("선택 : ");

        //scanf("%d", &menu); 아래 여섯줄처람 고침

        if (scanf("%d", &menu) != 1) {
            printf("숫자를 입력하세요.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        // 계좌 개설 
        if (menu == 1) {

            int id;
            char name[20];

            ACCOUNT* pSearch;

            if (cntAccount >= MAX_ACCOUNT) {

                printf("계좌를 추가할 수 없습니다.\n");
                continue;
            }

            printf("계좌번호 : ");
            scanf("%d", &id);

            pSearch = SearchAccount(accounts, cntAccount, id);

            if (pSearch != NULL) {

                printf("이미 존재하는 계좌번호입니다.\n");
                continue;
            }

            printf("예금주명 : ");
            scanf("%19s", name);

            accounts[cntAccount].id = id;

            strcpy(accounts[cntAccount].name, name);

            accounts[cntAccount].balance = 0;

            cntAccount++;

            printf("계좌가 개설되었습니다.\n");
        }

        // 입금 
        else if (menu == 2) {

            int id;
            int money;

            ACCOUNT* pAccount;

            printf("계좌번호 : ");
            scanf("%d", &id);

            pAccount = SearchAccount(accounts, cntAccount, id);

            if (pAccount == NULL) {

                printf("계좌가 존재하지 않습니다.\n");
                continue;
            }

            printf("입금액 : ");
            scanf("%d", &money);

            if (money <= 0) {

                printf("올바른 금액을 입력하세요.\n");
                continue;
            }

            pAccount->balance += money;

            printf("입금 완료.\n");
        }

        // 출금
        else if (menu == 3) {

            int id;
            int money;

            ACCOUNT* pAccount;

            printf("계좌번호 : ");
            scanf("%d", &id);

            pAccount = SearchAccount(accounts, cntAccount, id);

            if (pAccount == NULL) {

                printf("계좌가 존재하지 않습니다.\n");
                continue;
            }

            printf("출금액 : ");
            scanf("%d", &money);

            if (money <= 0) {

                printf("올바른 금액을 입력하세요.\n");
                continue;
            }

            if (pAccount->balance < money) {

                printf("잔액이 부족합니다.\n");
                continue;
            }

            pAccount->balance -= money;

            printf("출금 완료.\n");
        }

        // 종료 
        else if (menu == 0) {

            printf("프로그램 종료\n");
            break;
        }

        else {

            printf("잘못된 메뉴 선택입니다.\n");
        }
    }

    return 0;
}
    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_ACCOUNT 3

typedef struct {
    int id;             // 계좌번호
    char name[20];      // 예금주명
    int balance;        // 잔액
} ACCOUNT;


/* 전체 계좌 출력 */
void PrintAll(ACCOUNT *accounts, int cntAccount) {

    printf("\n-----------------------------\n");
    printf(" 계좌번호    예금주      잔액\n");
    printf("-----------------------------\n");

    for (int i = 0; i < cntAccount; i++) {
        printf("%8d %10s %10d\n",
            accounts[i].id,
            accounts[i].name,
            accounts[i].balance);
    }
    printf("-----------------------------\n");
}


/* 계좌 검색 */
ACCOUNT* SearchAccount(ACCOUNT* accounts, int count, int id) {

    for (int i = 0; i < count; i++) {

        if (accounts[i].id == id)
            return &accounts[i];
    }

    return NULL;
}
//bin : 1=입금, 0=춯금
void InOut(ACCOUNT* accounts, int count, int bin){
    int id, money;
    ACCOUNT* pSearch;

    printf("계좌번호 : ");
    scanf("%d", &id);

    pSearch = SearchAccount(accounts, count, id);

    if (pSearch == NULL) {
        printf("계좌가 존재하지 않습니다.\n");
        Sleep(3000);
        return;
    }

    printf(bin ? "입금액" : "출금액 : " );
    scanf("%d", &money);


    pSearch->balance += bin ? money : -money;

    printf(bin ? "입금 완료.\n" : "출금 완료.\n");
    Sleep(3000);
}

static char s_filename[] = "accountM1angment.dat";

void Save(ACCOUNT* accounts, int count){
    FILE* fp = fopen(s_filename, "wb");
    if (fp == NULL) {
        printf("%S 파일을 열 수 없습니다\n", s_filename);
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    for ( int i = 0; i < count; i++) {
        fwrite(accounts, sizeof(ACCOUNT), 1, fp);
    }
    fclose(fp);
}
void Load(ACCOUNT* accounts, int* pCount){
    FILE* fp = fopen(s_filename, "rb");
    *pCount = 0;
    if (fp == NULL) {
        printf("%S 파일을 열 수 없습니다\n", s_filename);
        return;
    }
    fread(pCount, sizeof(int), 1, fp);
    for ( int i = 0; i < *pCount; i++) {
        fread(&accounts[i], sizeof(ACCOUNT), 1, fp);
    }
    fclose(fp);
}
void Read2ndInfo(){
    FILE* fp = fopen(s_filename, "rb");
    ACCOUNT account;
    if (fp == NULL) {
        printf("%S 파일을 열 수 없습니다\n", s_filename);
        return;
    }
    fseek(fp, sizeof(int)+sizeof(ACCOUNT)*1, SEEK_SET);
    fread(&account, sizeof(ACCOUNT), 1, fp);
    printf("2nd:  %8d %8s %8d\n",
        account.id, account.name, account.balance);
    fclose(fp);
}
int main(void) {
    SetConsoleOutputCP(65001);
    ACCOUNT accounts[MAX_ACCOUNT] = {0};

    int cntAccount = 0, menu;
    Load(accounts, &cntAccount);
    Read2ndInfo();
    while (1) {

        PrintAll(accounts, cntAccount);

        printf("\n계좌개설(1) 입금(2) 출금(3) 종료(0)\n");
        printf("선택 : ");

       if (scanf("%d", &menu) != 1) {
            printf("숫자를 입력하세요.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        /* 계좌 개설 */
        if (menu == 1) {
            int id;
            char name[20];
            ACCOUNT* pSearch;
            if (cntAccount == MAX_ACCOUNT) {
                printf("계좌를 추가할 수 없습니다.\n");
                Sleep(3000);
                continue;
            }

            printf("계좌번호 : ");
            scanf("%d", &id);

            pSearch = SearchAccount(accounts, cntAccount, id);
            if (pSearch != NULL) {
                printf("이미 존재하는 계좌번호입니다.\n");
                Sleep(3000);
                continue;
            }

            printf("예금주명 : ");
            scanf("%19s", name);

            accounts[cntAccount].id = id;

            strcpy(accounts[cntAccount].name, name);

            accounts[cntAccount].balance = 0;

            cntAccount++;

            printf("계좌가 개설되었습니다.\n");
            Sleep(3000);
        }

        /* 입금 */
        else if (menu == 2) {
            InOut(accounts, cntAccount, 1);
        }

        /* 출금 */
        else if (menu == 3) {
            InOut(accounts, cntAccount, 0);
        }

        /* 종료 */
        else if (menu == 0) {

            printf("프로그램 종료\n");
            Sleep(3000);
            break;
        }

        else {
            printf("잘못된 메뉴 선택입니다.\n");
            Sleep(3000);
        }
    }
    Save(accounts, cntAccount);
    return 0;
}