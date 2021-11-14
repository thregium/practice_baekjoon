#include <stdio.h>

/*
문제 : 10 * 10 크기의 오목판에서 'X' 말을 하나 더 놓고 'X'가 이길 수 있는지 구한다.

해결 방법 : 모든 칸에 말을 놓아 보면서 이기는 경우가 있는지 보면 된다.

주요 알고리즘 : 구현, 브루트 포스
*/

char s[16][16];

int check(void) {
    int r = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i][j] == 'X' && s[i][j + 1] == 'X' && s[i][j + 2] == 'X' && s[i][j + 3] == 'X' && s[i][j + 4] == 'X') r = 1;
            if (s[j][i] == 'X' && s[j + 1][i] == 'X' && s[j + 2][i] == 'X' && s[j + 3][i] == 'X' && s[j + 4][i] == 'X') r = 1;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i][j] == 'X' && s[i + 1][j + 1] == 'X' && s[i + 2][j + 2] == 'X' && s[i + 3][j + 3] == 'X' && s[i + 4][j + 4] == 'X') r = 1;
        }
        for (int j = 4; j < 10; j++) {
            if (s[i][j] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 2][j - 2] == 'X' && s[i + 3][j - 3] == 'X' && s[i + 4][j - 4] == 'X') r = 1;
        }
    }
    return r;
}

int main(void) {
    int r = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i][j] != '.') continue;
            s[i][j] = 'X';
            r |= check();
            s[i][j] = '.';
        }
    }
    printf("%d", r);
    return 0;
}