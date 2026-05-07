#include <stdio.h>

void main() {
	int number = 21;
	
	printf("%c 게이트로 가새요\n", 'A' + number / 10);
	
	for(number = 0 ; number < 29; number++){
		printf("숫자 %2d는 %2c 게이트로 가새요\n", number, 'A' + number / 10);
	}
	
}
