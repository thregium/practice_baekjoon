#include <stdio.h>

/*
문제 : 최대 10 * 10 크기의 체스판과 비숍을 놓을 수 있는 칸들이 주어질 때, 서로간에 공격받지 않게 비숍을 최대한 놓을 수 있는 갯수를 출력한다.

해결 방법 : 비숍은 같은 색깔의 칸들만 움직일 수 있기 때문에 체스판을 두개로 나누어 생각한다. 먼저 같은 색 칸에서 비숍을 놓을 수 있는 칸들을 저장한 다음,
비숍을 놓는 경우와 놓지 않는 경우를 나누어 백트래킹을 실행한다. 현재 위치가 다른 비숍들에게 공격받는 위치인 경우 현재 칸에서는 비숍을 놓지 않고,
공격받지 않는 위치인 경우 두 가지를 전부 생각한다. 체스판의 끝에 도달하면 최댓값을 갱신한다. 현재 위치에서 나머지 모든 칸에 비숍을 놓아도 최댓값에 도달할 수 없다면 조기에 종료해 시간을 절약할 수 있다.

주요 알고리즘 : 백트래킹
*/

int board[16][16], odds[128], evens[128], chkln[2][16];
int oddi = 0, eveni = 0, maxo = 0, maxe = 0;
int n;

int big(int a, int b) {
    return a > b ? a : b;
}

void tracko(int p, int m) {
    if (p == oddi) {
        maxo = big(maxo, m);
        return;
    }
    if (oddi - p < maxo - m) return;
    int x = odds[p] / n, y = odds[p] % n;
    if (!chkln[0][(x + y - 1) / 2] && !chkln[1][(n - (x - y)) / 2]) {
        chkln[0][(x + y - 1) / 2]++;
        chkln[1][(n - (x - y)) / 2]++;
        tracko(p + 1, m + 1);
        chkln[0][(x + y - 1) / 2]--;
        chkln[1][(n - (x - y)) / 2]--;
    }
    tracko(p + 1, m);
}

void tracke(int p, int m) {
    if (p == eveni) {
        maxe = big(maxe, m);
        return;
    }
    if (eveni - p < maxe - m) return;
    int x = evens[p] / n, y = evens[p] % n;
    if (!chkln[0][(x + y) / 2] && !chkln[1][(n - 1 - (x - y)) / 2]) {
        chkln[0][(x + y) / 2]++;
        chkln[1][(n - 1 - (x - y)) / 2]++;
        tracke(p + 1, m + 1);
        chkln[0][(x + y) / 2]--;
        chkln[1][(n - 1 - (x - y)) / 2]--;
    }
    tracke(p + 1, m);
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j]) {
                if ((i + j) % 2) odds[oddi++] = i * n + j;
                else evens[eveni++] = i * n + j;
            }
        }
    }
    tracko(0, 0);
    tracke(0, 0);
    printf("%d", maxo + maxe);
    return 0;
}