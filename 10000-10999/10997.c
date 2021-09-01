#include <stdio.h>

/*
문제 : N(N <= 100) 크기의 달팽이 모양으로 별을 출력한다.

해결 방법 : 달팽이의 중심에서 시작해서 시계방향으로 밖으로 이동해가며 별을 찍으면 된다.
마지막 바퀴와 N = 1, 출력 형식에 유의한다.

주요 알고리즘 : 구현
*/

char res[512][512];

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    if (n == 1) {
        printf("*");
        return 0;
    }
    x = n * 2, y = n * 2 - 2;
    for (int i = 0; i < n * 4 - 1; i++) {
        for (int j = 0; j < n * 4 - 3; j++) res[i][j] = ' ';
    }
    res[1][1] = '\0', res[x][y] = '*';
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i * 4 - 2; j++) res[--x][y] = '*';
        for (int j = 1; j <= i * 4 - 2; j++) res[x][++y] = '*';
        for (int j = 1; j <= i * 4; j++) res[++x][y] = '*';
        for (int j = 1; j <= i * 4; j++) res[x][--y] = '*';
    }
    for (int i = 1; i <= n * 4 - 2; i++) res[--x][y] = '*';
    for (int i = 1; i <= n * 4 - 4; i++) res[x][++y] = '*';
    for (int i = 0; i < n * 4 - 1; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}