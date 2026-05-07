/*#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;   // 배열 이름 = 첫 번째 요소 주소

    printf("%d\n", arr[0]);
    printf("%d\n", *(p + 0));

    printf("%d\n", arr[1]);
    printf("%d\n", *(p + 1));

    return 0;
}*/
/*void change(int x) {
    x = 100;
}

int main() {
    int num = 10;
    change(num);

    printf("%d\n", num); // 여전히 10
}*/
#include <stdio.h>
/*void change(int *p) {
    *p = 100;   // 주소로 가서 값 변경
}

int main() {
    int num = 10;

    change(&num);

    printf("%d\n", num); // 100으로 바뀜
}*/
#include <stdio.h>
#include <stdlib.h>

void change(int *arr) {
    arr[0] = 999;
}

int main() {
    int arr[3] = {1, 2, 3};
    int i;

    change(arr);
/*    change(arr+1);
    change(arr+2);*/

/*    printf("%d\n", arr[0]); // 999
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
*/	
   for(i = 0; i < 3; i++){
    	printf("%d\n", arr[i]);
	}

	free(arr);	
}
