#include <stdio.h>

/*
문제 : 주어진 형태의 페그 솔리테어 판에서 핀의 개수를 최소로 줄이도록 움직일 때, 핀의 개수와
움직인 횟수를 구한다. 처음 있는 핀의 개수는 8개 이하다.

해결 방법 : 핀을 움직이는 모든 경우를 시도해보면서 핀의 개수가 최소일 때의 핀 개수를 구하면 된다.
움직인 횟수는 항상 같기 때문에 처음 상태에서의 핀 개수에서 그 값을 빼면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : GCPC 2013 F번
*/

char board[8][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int best = 9, mov;

int isvalid(int x, int y, int d) {
    if (board[x + dxy[d][0]][y + dxy[d][1]] != 'o') return 0;
    else if (board[x + dxy[d][0] * 2][y + dxy[d][1] * 2] != '.') return 0;
    return 1;
}

void track(int m) {
    int cnt = 0;
    for (int i = 2; i <= 6; i++) {
        for (int j = 2; j <= 10; j++) {
            if (board[i][j] == 'o') {
                cnt++;
                for (int k = 0; k < 4; k++) {
                    if (isvalid(i, j, k)) {
                        board[i][j] = '.';
                        board[i + dxy[k][0]][j + dxy[k][1]] = '.';
                        board[i + dxy[k][0] * 2][j + dxy[k][1] * 2] = 'o';
                        track(m + 1);
                        board[i][j] = 'o';
                        board[i + dxy[k][0]][j + dxy[k][1]] = 'o';
                        board[i + dxy[k][0] * 2][j + dxy[k][1] * 2] = '.';
                    }
                }
            }
        }
    }
    if (cnt < best) {
        best = cnt;
        mov = m;
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 2; i <= 6; i++) {
            scanf("%s", board[i] + 2);
        }
        best = 9, mov = -1;
        track(0);
        printf("%d %d\n", best, mov);
    }
    return 0;
}