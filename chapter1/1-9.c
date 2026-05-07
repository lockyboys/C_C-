/*#include <stdlib.h> 

int main(){
	int n;
	int i;
	scanf("%d",&n);
	
	int Score[n];
	
	Score = (int *)malloc(n *sizeof(int));
	
	for(i=0;i<n;i++){
		Score[i]=i+10;
		printf("%d",Score[i]);
	}
	free(Score))
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;

    scanf("정수값을 입력해 주세요? %d", &n);

    int *Score;  // 포인터로 선언
    Score = (int *)malloc(n * sizeof(int));

    // malloc 실패 체크 (좋은 습관)
    if (Score == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        Score[i] = i + 10;
        printf("%d \n", Score[i]);
    }

    free(Score);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;

    printf("정수값을 입력해 주세요? ");
    scanf("%d", &n);

    /*int *Score;
    Score = (int *)malloc(n * sizeof(int));*/
    int *Score = (int *)malloc(n * sizeof(int));

    if (Score == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (i = 0; i <= n; i++) {
        Score[i] = i * 10;
        printf("%3d\n", Score[i]);
        printf("%p\n", &Score[i]);
    }

    free(Score);

    return 0;
}
