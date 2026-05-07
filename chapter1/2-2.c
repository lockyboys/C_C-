#include <stdio.h>
#include <stdlib.h>     //   srand, rand
#include <time.h>

void main(){
    int user, computer;
    int userwin, comwin;

    srand(time(NULL));
    while(user != 3){
        computer = rand() % 3;

        printf("가위(0) 바위(1) 보(2) 종료(3) : ");
        scanf("%d", &user);

        userwin = ((computer + 1) % 3 == user);
        comwin = ((user + 1) % 3 == computer);

        printf("사용자 = %d 컴퓨터 = %d\n", user, computer);
        printf("컴퓨터 슻? %d\n", comwin);
        printf("사용자 승? %d\n", userwin);
    }
    printf("가위(0) 바위(1) 보(2) 게암이 종료(3) 되었습니다!!!!!2");
}