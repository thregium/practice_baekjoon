#include <stdio.h>

/*
문제 : 5 * 6 크기의 격자에서 한 칸을 누르면 그 칸과 상하좌우 칸들의 상태가 반전된다고 한다.
이때 모든 칸의 상태를 0으로 만들기 위해 눌러야 하는 칸들을 출력한다.

해결 방법 : 맨 윗줄에서 브루트 포스로 모든 가능성에 대해 검사해보고, 이후 줄들은 윗줄의 모든 칸들을 0으로 만들도록 한다.
마지막 줄까지 끝나면 마지막줄의 상태가 0인지 확인하고 0이라면 그 때의 누른 칸들을 출력, 아니라면 계속 탐색한다.

주요 알고리즘 : 그리디 알고리즘, 브루트 포스

출처 : GNY 2002 F번
*/

int puzzle[8][8], cpy[8][8], sel[8][8];

void press(int x, int y) {
    cpy[x][y] = !cpy[x][y];
    if (x > 0) cpy[x - 1][y] = !cpy[x - 1][y];
    if (y > 0) cpy[x][y - 1] = !cpy[x][y - 1];
    if (x < 4) cpy[x + 1][y] = !cpy[x + 1][y];
    if (y < 5) cpy[x][y + 1] = !cpy[x][y + 1];
}

int check(int b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) cpy[i][j] = puzzle[i][j];
    }
    for (int i = 0; i < 6; i++) {
        if (b & (1 << i)) {
            press(0, i);
            sel[0][i] = 1;
        }
        else sel[0][i] = 0;
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (cpy[i - 1][j]) {
                press(i, j);
                sel[i][j] = 1;
            }
            else sel[i][j] = 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (cpy[4][i]) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int tt = 1; tt <= n; tt++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &puzzle[i][j]);
            }
        }
        for (int i = 0; i < 64; i++) {
            if (check(i)) {
                printf("PUZZLE #%d\n", tt);
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 6; k++) {
                        printf("%d ", sel[j][k]);
                    }
                    printf("\n");
                }
                break;
            }
        }
    }
    return 0;
}