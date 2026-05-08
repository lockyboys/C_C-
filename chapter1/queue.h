//#ifndef QUEUE_H
//#define QUEUE_H

typedef int element;

void EnQueue(element data);
element DeQueue();
element PeekQueue();
int IsQueueEmpty();
int IsQueueFull();
void PrintQueue(char *title);

//#endif