/*
    마방진 만들기
    - 맨 윗줄 가운데에서 1로 시작
    - 왼쪽 위 칸으로 이동하면서 1씩 증가된 수로 채우기 (col + size -1) % size
    - 새로 채우려는 자리에 이미 숫자가 있으면 기존 위 바로 아래로 가기 (row + 1) % size
    - 모든 이동시 맨 위와 맨 아래, 맨 오른쪽과 맨 왼쪽은 연결 된 것으로 본다
*/

#include <stdio.h>

void main(){
    
    int magic[9][9] = { 0 };

    int  i, row, col, newrow, newcol;
    int  size;

    printf("마방진 크기(3/5/7/9): ");
    scanf("%d", &size);

    row = 0;
    col = size / 2;

    for (i = 1; i <= size * size; i++) {
        //숫자 채우기
        magic[row][col] = i;
        // 다음 위치 정하기
        newrow = (row + size - 1) % size;
        newcol = (col + size - 1) % size;
        if (magic[newrow][newcol] != 0) {
            newrow = (row + 1) % size;
            newcol = col;
        }
        row = newrow;
        col = newcol;
    }

    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) 
            printf(" _2D[%d][%d] = %3d", row, col, *(magic[row] + col));
        printf("\n");
    }

    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) 
            printf("%3d", *(magic[row] + col));
        printf("\n");
    }
/*
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) 
            printf("%3d", *(_2D[row] + col));
        printf("\n");
    }
*/
}