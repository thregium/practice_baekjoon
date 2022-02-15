#include <stdio.h>

/*
문제 : N * 2(N <= 100)장의 카드를 2명이 나누어 가지고 문제에 주어진 규칙으로 카드게임을 한다.
두 사람이 가진 카드들이 주어질 때, 두 사람의 점수를 구한다.

해결 방법 : 문제에 주어진 규칙을 시뮬레이션하여 점수를 확인하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JOI 2008예 3번
*/

int card[256];

int main(void) {
    int n, x, h, sc, gc, turn, tmp;
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            card[x] = 1;
        }
        h = 0, sc = n, gc = n, turn = 0;
        while (sc && gc) {
            if (turn & 1) {
                tmp = 0;
                for (int i = h + 1; i <= n * 2; i++) {
                    if (card[i] == 0) {
                        tmp = 1;
                        card[i] = -1;
                        gc--;
                        h = i;
                        break;
                    }
                }
                if (!tmp) h = 0;
            }
            else {
                tmp = 0;
                for (int i = h + 1; i <= n * 2; i++) {
                    if (card[i] == 1) {
                        tmp = 1;
                        card[i] = -1;
                        sc--;
                        h = i;
                        break;
                    }
                }
                if (!tmp) h = 0;
            }
            turn++;
        }
        printf("%d\n%d\n", gc, sc);
        for (int i = 1; i <= n * 2; i++) card[i] = 0;
    }
    return 0;
}