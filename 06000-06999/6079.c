#include <stdio.h>

/*
문제 : N * N(N <= 30) 크기의 체커 판에 자신의 말들('K')과 상대의 말들('o')이 있다. 상대의 말들을 모두 잡는 방법이
유일하게 존재한다고 할 때, 그 방법을 구한다. 갈 수 있는 칸은 '+', 갈 수 없는 칸은 '-'로 주어지고, 말들은 대각선으로만
움직일 수 있다.

해결 방법 : 먼저 상대의 말 개수를 센 다음, 모든 자신의 말들에 대해서 백트래킹을 통해 말들을 모두 잡는 방법을 찾는다.
대각선 방향으로 2칸씩 움직이며 상대의 말이 있는지 확인한 다음, 남아있다면 그 말을 지우고 그곳으로 이동하면 된다.
이동하는 칸은 당연히 빈 칸이어야 한다.
상대의 모든 말을 지웠음이 확인된다면 그때까지 움직인 경로를 출력하고 프로그램을 종료하면 된다.

주요 알고리즘 : 구현, 백트래킹

출처 : USACO 2008D B1번
*/

char board[32][32], vis[32][32];
int mvs[1024][2];
int dxy[4][2] = { {2, 2}, {2, -2}, {-2, -2}, {-2, 2} };
int n, fin = 0;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (board[x][y] != '+' || board[x + (dxy[d ^ 2][0] >> 1)][y + (dxy[d ^ 2][1] >> 1)] != 'o') return 0;
    if (vis[x + (dxy[d ^ 2][0] >> 1)][y + (dxy[d ^ 2][1] >> 1)]) return 0;
    return 1;
}

void track(int o, int op, int x, int y) {
    if (o == op) {
        fin = 1;
        for (int i = 0; i < o; i++) {
            printf("%d %d\n", mvs[i][0], mvs[i][1]);
        }
        printf("%d %d", x + 1, y + 1);
        return;
    }

    mvs[op][0] = x + 1;
    mvs[op][1] = y + 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], i)) {
            vis[x + (dxy[i][0] >> 1)][y + (dxy[i][1] >> 1)] = 1;
            track(o, op + 1, x + dxy[i][0], y + dxy[i][1]);
            vis[x + (dxy[i][0] >> 1)][y + (dxy[i][1] >> 1)] = 0;
        }
    }
}

int main(void) {
    int o = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'o') o++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'K') {
                track(o, 0, i, j);
                if (fin) return 0;
            }
        }
    }
    if (!fin) printf("impossible");
    return 0;
}