/*
    문자열 관련 함수 사용 예
*/  

#include <stdio.h>

void main(){
    
    int _2D[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        (9, 10, 11, 12),
        (13, 14, 15, 16)
    };

    int  row, col;
    int  count = 1;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            _2D[row][col] = count++;
        }
    }

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) 
            printf(" _2D[%d][%d] = %3d", row, col, *(_2D[row] + col));
        printf("\n");
    }
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) 
            printf("%3d", *(_2D[row] + col));
        printf("\n");
    }
}