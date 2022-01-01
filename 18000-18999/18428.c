#include <stdio.h>

/*
문제 : N * N(3 <= N <= 6) 크기의 방에 학생과 선생이 있다. 선생은 막히지 않은 상하좌우 칸들을 볼 수 있다면,
장애물을 3개 놓아 모든 학생을 볼 수 없게 할 수 있는 지 구한다.

해결 방법 : 장애물을 3개 놓는 모든 방법을 브루트 포스로 해보면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹
*/

char s[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int res = 0;

int isvalid(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (s[x][y] == 'T' || s[x][y] == 'O') return 0;
    return 1;
}

void track(int n, int x) {
    if (x == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] != 'T') continue;
                for (int d = 0; d < 4; d++) {
                    for (int st = 1; isvalid(n, i + dxy[d][0] * st, j + dxy[d][1] * st); st++) {
                        if (s[i + dxy[d][0] * st][j + dxy[d][1] * st] == 'S') return;
                    }
                }
            }
        }
        res = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'X') {
                s[i][j] = 'O';
                track(n, x + 1);
                s[i][j] = 'X';
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &s[i][j]);
        }
    }
    track(n, 0);
    printf("%s", res ? "YES" : "NO");
    return 0;
}