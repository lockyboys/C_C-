/*

    중위표기식 : 5*(6-2)-7*3+4
    중위표기식 : 562-*73*-4+
    [1단계]식을 연산자, 피 연산자 단위로 읽으며 처리
    1. 피연산자 -> 랑상 결과로 출력.
    2. 연산자 -> 아래 방법으로 스택에 저장
        if (새 연산자의 우선순위 > 스택의 top연산자 우선순위) || (스택 비었음) -> 스택에 저장
        else -> top의 연산자를 pop하여 결과로 출력.
    3. '(' -> 무조건 스택에 push(우선순순위 가장 낮음)
    4. ')' -> 스택에서 '('까지 pop하여 결과로 출력. '('는 pop하여 버림
    [2단계] 스택이 빌때까지 연산자를 popgkdu rufrhkfh cnffur
*/


#include <stdio.h>
//#include <stdlib.h>
#include <windows.h>
#include "stack.h"

int GetPriority(char op) {

    if ( op == '+' || op == '-')
        return 1;
    else
        return 2;

}

int ComparePriority(char op1, char op2) {

    int p1 = GetPriority(op1);
    int p2 = GetPriority(op2);
    int result = p1 - p2;
    
    return result;
}
void infix2Postfix(char infix[100], char postfix[100]) {
    int idxIn = 0, idxPost = 0;

    while (infix[idxIn] != '\0') {
        char symbol = infix[idxIn++];
        if (symbol == '(')
            Push(symbol);
        else if (symbol == ')') {
            while(1) {
                int ch = Pop();
                if (ch == '(')
                    break;
                postfix[idxPost++] = ch;
            }
        }
        else if (symbol >= 0 && symbol <= 9) {
            postfix[idxPost++] = symbol;
        }
        else {
            while (1) {
                if (IsStackEmpty()
                    || Peek() == '('
                    || ComparePriority(Peek(), symbol) < 0) {
                    Push(symbol);
                    break;
                }
                postfix[idxPost++] = Pop();
            }
        }
    }

    while (!IsStackEmpty()) {
        postfix[idxPost++] = Pop();
    }
    postfix[idxPost++] = '\0';
}


void main() {
    SetConsoleOutputCP(65001);
    element data;

    char infix[100] = "5*(6-2)-7*3+4";
    char postfix[100];

    printf("중위표기식 : %s\n", infix);
    infix2Postfix(infix, postfix);
    printf("중위표기식 : %s\n", postfix);

}