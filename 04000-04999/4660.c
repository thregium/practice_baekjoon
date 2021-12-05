#include <stdio.h>

/*
문제 : N(N <= 4)명이 길이 L(L < 80)의 보드에서 게임을 한다. 각 사람이 C(C <= 200)개의 카드를 차례로 열어가며 진행하고,
각 카드를 열었을 때 현재 칸 이후의 첫 해당 색이 나오는 칸으로 이동한다. 2개의 색이 나오는 경우가 있는데,
이는 이를 두 번 진행하면 된다.
만약 마지막 칸에 도착하거나 마지막 칸을 지나친 경우 게임을 이기게 될 때, 게임을 이기는 사람과 그 때까지 연 카드의 수를 구한다.
이긴 사람이 없다면 그때까지 연 카드의 수만 출력한다.

해결 방법 : 직접 게임의 진행을 시뮬레이션하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 2000 C번
*/

char board[128], buff[4];
int player[4];

int main(void) {
    int n, l, c, t = 0, e, p;
    while (1) {
        scanf("%d %d %d", &n, &l, &c);
        if (n == 0) break;
        for (int i = 0; i < n; i++) player[i] = -1;
        scanf("%s", board);
        e = 0, p = 0;
        for (int i = 0; i < c; i++) {
            scanf("%s", buff);
            if (e) continue;
            for (int ii = 0; buff[ii]; ii++) {
                t = 0;
                for (int k = player[p] + 1; k < l; k++) {
                    if (board[k] == buff[ii]) {
                        player[p] = k;
                        t = 1;
                        break;
                    }
                }
            }
            if (!t || player[p] == l - 1) {
                printf("Player %d won after %d cards.\n", p + 1, i + 1);
                e = 1;
            }
            p = (p + 1) % n;
        }
        if (!e) printf("No player won after %d cards.\n", c);
    }
    return 0;
}