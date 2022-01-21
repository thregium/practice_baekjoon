#include <stdio.h>

/*
문제 : H * W(H, W <= 30) 크기의 알파벳 대문자로 이루어진 블록들이 쌓여 있고,
그 외 칸들은 빈 칸으로 되어있다. 상하 또는 좌우로 N(2 <= N <= 30)개 이상이 같은 블록으로 연결되면
그 블록들은 사라지고 남은 블록들은 아래로 떨어진다. 이는 연쇄적으로 일어난다.
이때, 좌우로 2개의 칸을 바꾸어(빈칸 포함) 모든 블록들을 없앨 수 있는 지 구한다.
맨 처음에는 블록이 N개 이상 동일하게 연결되지 않았다.

해결 방법 : 모든 좌우로 인접한 2개의 칸에 대해 바꾸어 본 다음 모든 블록들이 사라지는 지 확인한다.
N칸 이상이 동일하게 되어있는 칸이 있다면 이를 지운 다음(바로 지우면 안되고 찾은 위치를 표시한 다음
그 칸들을 지워야 한다.) 모든 블록들을 내린다. 투 포인터를 사용하면 좋지만 사용하지 않아도 무방하다.
여러 칸, 여러 블록이 떨어질 수 있음에 유의한다. 이를 블록들이 사라지지 않을 때 까지 반복한 후
반복이 끝나면 모든 블록들이 사라졌는 지 확인한다. 한번이라도 모두 사라졌다면 없앨 수 있는 것이고,
그러한 경우가 없다면 없앨 수 없는 것이다.

주요 알고리즘 : 구현, 시뮬레이션, 브루트 포스

출처 : JAG 2010S 3번
*/

char orig[32][32], board[32][32], temp[32][32];

void swapc(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int findnbyn(int h, int w, int n) {
    int r = 0, c;
    for (int i = 0; i < h; i++) {
        c = 1;
        for (int j = 1; j <= w; j++) {
            if (board[i][j] != '.' && board[i][j] == board[i][j - 1]) c++;
            else {
                if (c >= n) {
                    for (int k = j - 1; k >= j - c; k--) temp[i][k] = '*';
                    r++;
                }
                c = 1;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        c = 1;
        for (int j = 1; j <= h; j++) {
            if (board[j][i] != '.' && board[j][i] == board[j - 1][i]) c++;
            else {
                if (c >= n) {
                    for (int k = j - 1; k >= j - c; k--) temp[k][i] = '*';
                    r++;
                }
                c = 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (temp[i][j] == '*') board[i][j] = '.';
            temp[i][j] = '.';
        }
    }
    return r;
}

void fall(int h, int w) {
    int r = 1;
    while (r) {
        r = 0;
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '.' && board[i - 1][j] != '.') {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = '.';
                    r++;
                }
            }
        }
    }
}

int checkres(int h, int w, int n, int x, int y, int d) {
    //if (orig[x][y] == '.' || (!d && orig[x + 1][y] == '.') || (d && orig[x][y + 1] == '.')) return 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) board[i][j] = orig[i][j];
    }
    swapc(&board[x][y], d ? &board[x][y + 1] : &board[x + 1][y]);

    fall(h, w);
    while (findnbyn(h, w, n)) {
        fall(h, w);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) if (board[i][j] != '.') return 0;
    }
    return 1;
}

int main(void) {
    int h, w, n, r = 0;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < h; i++) {
        scanf("%s", orig[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //if (i < h - 1) r |= checkres(h, w, n, i, j, 0);
            if (j < w - 1) r |= checkres(h, w, n, i, j, 1);
        }
    }
    printf("%s\n", r ? "YES" : "NO");
    return 0;
}