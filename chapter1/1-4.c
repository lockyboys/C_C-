#include <stdio.h>
#include <stdlib.h>


int main(){
int **arr;
int row = 3, col = 4;
int i;
int j;
	// 1. 행(row) 포인터 배열 생성
	arr = (int **)malloc(sizeof(int *) * row);
	
	// 2. 각 행마다 열(col) 배열 생성
	for (i = 0; i < row; i++) {
	    arr[i] = (int *)malloc(sizeof(int) * col);
	}
		for (i = 0; i < row; i++ ){
		for(j = 0; j < col ; j++ ){
			arr[i][j]=i*j;
		}
	}
	
	for (i = 0; i < row; i++ ){
		for(j = 0; j < col ; j++ ){
			printf("[%2d%2d%2d]", i, j,arr[i][j]);
		}
		printf("\n");
	}
	
	free(arr);
    

    return 0;
}
