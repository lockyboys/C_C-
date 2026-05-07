/*

    중위표기식 : 5*(6-2)-7*3+4
    중위표기식 : 562-*7*3-4+
    [1단계]tlrdmf dustkswk, vldustkswk eksdnlfh dkfrdmau cjfl
    1. 피연산자 -> 항상 스택에 push
    2. 연산자 -> 필요항 맘큼의 피연산자를 스택에 pop하여 연산한 후 연산결과를 스택에 push.
    [2단계]마지막에 스택에 남은 값이 결과

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
void Infix2Postfix(char infix[100], char postfix[100]) {
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
int CalcPostfix(char postfix[100]) {
    int idxPost = 0;
    while (postfix[idxPost] != '\0') {
        char ch = postfix[idxPost++];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {    //연산자
            int rightOperand = Pop() - '0';
            int leftOperand = Pop() - '0';
            int result = 0;
            if (ch == '+') result = leftOperand + rightOperand;
            else if (ch == '-') result = leftOperand - rightOperand;
            else if (ch == '*') result = leftOperand * rightOperand;
            else if (ch == '/') result = leftOperand / rightOperand;
            Push(result + '0');
        } 
        else {  //피연산자
            Push(ch);
        }
    }
    return Pop() - '0';
}

void main() {
    SetConsoleOutputCP(65001);
    element data;

    char infix[100] = "5*(6-2)-7*3+4";
    char postfix[100];
    int result;

    printf("중위표기식 : %s\n", infix);
    Infix2Postfix(infix, postfix);
    printf("중위표기식 : %s\n", postfix);

    result = CalcPostfix(postfix);
    printf("result=%d\n", result);

    PrintStack("Pop 후 스택4");

    PrintStack("Pop 후 스택4");

}