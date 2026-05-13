#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define COLS 160
#define ROWS 40
#define MAX_LENGTH 100
#define FOOD_COUNT 100

char board[ROWS][COLS];

int gameOver = 0;
int score = 0;

// 뱀 머리
int snakeX = 5;
int snakeY = 5;

// 이동 방향
int dirX = 1;
int dirY = 0;

// 몸통 좌표
int tailX[MAX_LENGTH];
int tailY[MAX_LENGTH];

int tailLength = 3;

// 먹이
int foodX[FOOD_COUNT];
int foodY[FOOD_COUNT];

void create_food() {

    for (int f = 0; f < FOOD_COUNT; f++) {

        while (1) {

            int newX = rand() % (COLS - 2) + 1;
            int newY = rand() % (ROWS - 2) + 1;

            int collide = 0;

            // 머리 충돌
            if (newX == snakeX &&
                newY == snakeY) {

                collide = 1;
            }

            // 몸통 충돌
            for (int i = 0; i < tailLength; i++) {

                if (newX == tailX[i] &&
                    newY == tailY[i]) {

                    collide = 1;
                    break;
                }
            }

            // 다른 먹이와 충돌
            for (int i = 0; i < f; i++) {

                if (newX == foodX[i] &&
                    newY == foodY[i]) {

                    collide = 1;
                    break;
                }
            }

            if (!collide) {

                foodX[f] = newX;
                foodY[f] = newY;
                break;
            }
        }
    }
}

void clear_board() {

    for (int y = 0; y < ROWS; y++) {

        for (int x = 0; x < COLS; x++) {

            if (x == 0 || y == 0 ||
                x == COLS - 1 || y == ROWS - 1) {

                board[y][x] = '#';
            }
            else {
                board[y][x] = ' ';
            }
        }
    }
}

void draw_food() {

    for (int i = 0; i < FOOD_COUNT; i++) {

        board[foodY[i]][foodX[i]] = '*';
    }
}

void draw_snake() {

    // 머리
    board[snakeY][snakeX] = '@';

    // 몸통
    for (int i = 0; i < tailLength; i++) {
        board[tailY[i]][tailX[i]] = 'o';
    }
}

void print_board() {

    system("cls");

    printf("SCORE : %d\n", score);

    for (int y = 0; y < ROWS; y++) {

        for (int x = 0; x < COLS; x++) {
            putchar(board[y][x]);
        }

        putchar('\n');
    }
}

void read_keyboard() {

    if (_kbhit()) {

        int ch = _getch();

        switch (ch) {

            case 'w':

                if (dirY != 1) {
                    dirX = 0;
                    dirY = -1;
                }

                break;

            case 's':

                if (dirY != -1) {
                    dirX = 0;
                    dirY = 1;
                }

                break;

            case 'a':

                if (dirX != 1) {
                    dirX = -1;
                    dirY = 0;
                }

                break;

            case 'd':

                if (dirX != -1) {
                    dirX = 1;
                    dirY = 0;
                }

                break;

            case 'q':
                gameOver = 1;
                break;
        }
    }
}

void move_tail() {

    // 뒤에서 앞으로 이동
    for (int i = tailLength - 1; i > 0; i--) {

        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }

    // 첫 몸통은 머리 위치 따라감
    if (tailLength > 0) {

        tailX[0] = snakeX;
        tailY[0] = snakeY;
    }
}

void move_snake() {

    move_tail();

    snakeX += dirX;
    snakeY += dirY;

    // 벽 충돌
    if (snakeX <= 0 || snakeX >= COLS - 1 ||
        snakeY <= 0 || snakeY >= ROWS - 1) {

        gameOver = 1;
    }

    // 자기 몸 충돌
    for (int i = 0; i < tailLength; i++) {

        if (snakeX == tailX[i] &&
            snakeY == tailY[i]) {

            gameOver = 1;
        }
    }

    // 먹이 먹기
    for (int i = 0; i < FOOD_COUNT; i++) {

        if (snakeX == foodX[i] &&
            snakeY == foodY[i]) {

            score += 10;

            if (tailLength < MAX_LENGTH - 1) {
                tailLength++;
            }

            // 먹이 새 위치 생성
            foodX[i] = rand() % (COLS - 2) + 1;
            foodY[i] = rand() % (ROWS - 2) + 1;
        }
    }
}

int main() {

    srand((unsigned int)time(NULL));

    create_food();

    while (!gameOver) {

        read_keyboard();

        move_snake();

        clear_board();

        draw_food();

        draw_snake();

        print_board();

        Sleep(100);
    }

    printf("\nGAME OVER\n");
    printf("FINAL SCORE : %d\n", score);

    return 0;
}