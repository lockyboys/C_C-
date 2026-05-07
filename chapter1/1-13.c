/*#include <stdio.h>

void main(){

    int i = NULL, j = NULL;
    char *name = "���¾� ���ȴ�";

    printf("%d",i);
    for(j=0; j < 4;j++)
	{
		printf("%s",*name + j);
	}	printf("%s",*name + j);
}*/
#include <stdio.h>

int main() {

    int i = 0, j = 0;
    char *name = "안녕하세요!!!";

    printf("%d\n", i);
    printf(" %c", *(name + 0));
    printf(" %c\n", *(name + 1));
    // ��� 1: �� ���ھ� ���
    for (j = 0; j < 16; j++) {
        printf("%c", *(name + j));
    }

    printf("\n");

    return 0;
}
