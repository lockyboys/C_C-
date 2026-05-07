#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
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

    PrintStack("현재 스택");

    data = Pop();
    printf("Pop: %d\n", data);

    PrintStack("Pop 후 스택");

    PrintStack("Pop 후 스택");

    PrintStack("Pop 후 스택");

    PrintStack("Pop 후 스택4");

    PrintStack("Pop 후 스택5");

    PrintStack("Pop 후 스택6");

    return 0;
}