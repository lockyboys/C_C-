/*
    구조체
*/
#include <stdio.h>
#include <string.h>

typedef struct {   /*  typedef struct _StUDENT { */
    int id;
    char name[20];
    int score;
} STUDENT;
/*typedef struct _StUDENT StUDENT;*/

void PrintInfo( STUDENT *st){
    printf("학번:%d 이름:%s 총점:%d\n",  (*st).id, st -> name, st -> score);
}
void main() {
    STUDENT st1 = {10, "홍길동", 99};

    PrintInfo(&st1);
}