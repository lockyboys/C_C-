#include <stdio.h>

struct student {
    char name[12];
    int kor, math, sum, total;
};

int main () {

    struct student s[3] = {{"홍길동", 90, 85}, {"이순신", 88, 91}, {"아무개", 80, 75}};
    struct student *p;

    p = &s[0];
    p = &(*p);
    p[1].sum = p[1].kor + p[2].math;
    p[1].total = p[1].sum + p[0].kor + p[0].math;

    printf("%d\n", p[1].sum + p[1].total);
    {
        /* data */
    };
    
}