#include <stdio.h>

/*
문제 : N * N(N <= 4) 크기의 판에서 장애물의 위치가 주어질 때, 룩을 서로 공격받게 하지 않으며 최대 몇 개까지
배치 가능한지 구한다. 장애물이 있는 칸에는 룩을 놓을 수 없고, 각 룩들은 장애물을 넘을 수 없다.

해결 방법 : 백트래킹을 통해 경우의 수를 센다. 왼쪽 위 칸부터 차례로 룩들을 놓으며 공격받지 않는 모든 배치 가운데
가장 많은 룩을 배치하는 경우를 구하면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : MidC 1998 C번 // CTUF 2003 G번
*/

char board[8][8];
int best = 0;

void track(int n, int x, int y, int c) {
    if (x == n) {
        if (c > best) best = c;
        return;
    }
    int v = 1;
    if (board[x][y] == 'X') v = 0;
    for (int i = x + 1; i < n; i++) {
        if (board[i][y] == 'X') break;
        if (board[i][y] == '#') v = 0;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (board[i][y] == 'X') break;
        if (board[i][y] == '#') v = 0;
    }
    for (int i = y + 1; i < n; i++) {
        if (board[x][i] == 'X') break;
        if (board[x][i] == '#') v = 0;
    }
    for (int i = y - 1; i >= 0; i--) {
        if (board[x][i] == 'X') break;
        if (board[x][i] == '#') v = 0;
    }
    if (v) {
        board[x][y] = '#';
        track(n, y == n - 1 ? x + 1 : x, y == n - 1 ? 0 : y + 1, c + 1);
        board[x][y] = '.';
    }
    track(n, y == n - 1 ? x + 1 : x, y == n - 1 ? 0 : y + 1, c);
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }
        best = 0;
        track(n, 0, 0, 0);
        printf("%d\n", best);
    }
    return 0;
}