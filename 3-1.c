/*
    하노이탑을 구하는 프로그램을 재귀 함수 이용하여 만들어 봅시다
    초기작업
    조건검사 <- 한단계 작응 문제 규정
    조건검사 <- 최소항의 문제 규정

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "stack.h"


void main() {
    SetConsoleOutputCP(65001);
    element data;

    PrintStack("초기 스택");
    Push(10); PrintStack("Push(10)");
    Push(20); PrintStack("Push(20)");
    Push(30); PrintStack("Push(30)");
    data = Peek(); PrintStack("Peek()");
    printf("\tPeek data = %d\n", data);
    data = Pop(); PrintStack("Pop()");
    printf("\tPop data = %d\n", data);
    data = Pop(); PrintStack("Pop()");
    printf("\top data = %d\n", data);
    Push(40); PrintStack("Push(40)");
    data = Pop(); PrintStack("Pop()");
    printf("\top data = %d\n", data);

}