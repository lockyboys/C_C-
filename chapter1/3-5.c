#include <stdio.h> 

void main() {
    int inum = 10;
    int* pInum = NULL;

    pInum = &inum;

    printf("*plnum=%d\n", *pInum);

    *pInum = *pInum + 1;
    printf("inum = %d, *plnum = %d\n", inum, *pInum);

}