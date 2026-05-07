//#ifndef STACK_H
//#define STACK_H

//#include "stack.c"

typedef int element;

void Push(element data);
element Pop();
element Peek();
int IsStackEmpty();
int IsStackFull();
void PrintStack(char *title);

//#endif