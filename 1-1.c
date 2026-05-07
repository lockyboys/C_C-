/*#include<stdio.h>

int main()
{
	int num = 10;
	int *P;
	
	P = &num;
	
	printf("%p\n", &num);
	printf("%d byte\n", sizeof(num));
	printf("%d byte\n", sizeof(p));
	printf("%d\n", *p);
	printf("%p\n", p);
	printf("%p\n", &p);
	
	return 0;
}*/
#include <stdio.h>

int main() {
    int num = 10;
    int *p;   // 
    

    p = &num;

    printf("%p\n", (void*)&num);
    printf("%zu byte\n", sizeof(num));
    printf("%zu byte\n", sizeof(p));
    printf("%d\n", *p);
    printf("%p\n", (void*)p);
    printf("%p\n", (void*)&p);

    return 0;
}
