/*
    구조체 배열 
*/
#include <stdio.h>
#include <string.h>
#define COUNT   3
typedef struct {   /*  typedef struct _StUDENT { */
    int id;
    char name[20];
    int score;
} STUDENT;
/*typedef struct _StUDENT StUDENT;*/

void PrintInfo( STUDENT *st, int count){
    for (int i =0; i <count;i++) {
        printf("학번:%d 이름:%s 총점:%d\n",  (*st).id, st -> name, st -> score);
        st++;
    }
}
void main() {
    STUDENT st1[COUNT] = { 
        {10, "홍길동", 99},
        {13, "김철수", 88},
        {14, "이윤희", 77}
    };
    printf("학번:%d 이름:%s 총점:%d\n", st1[1].id, st1[1].name, st1[1].score);
    PrintInfo(st1, COUNT);
}