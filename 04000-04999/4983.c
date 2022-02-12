#include <stdio.h>

/*
문제 : R * C(R, C <= 20) 크기의 판에서 퍽을 이동시킨다. 퍽은 상하좌우로 이동 가능하며,
벽에 부딪힐 때 까지 이동하고, 부딪힌 벽은 깨진다. 이때, 벽에 닿지 않고 도착점에도 닿지 않는 경우
퍽을 잃어버려 실패하게 된다. 도착점에 닿는다면 벽에 닿지 않더라도 성공이다.
이때, 주어진 판에서 퍽을 10회 내에 원하는 대로 이동시키는 것이 가능한 지 구하고,
가능한 경우 최소 이동 횟수를 구한다.

해결 방법 : 10회동안 이동시키는 방법은 4^10가지로 모든 경우를 살펴볼 수 있다.
따라서, 모든 경우를 살펴보도록 하며 가장 빠르게 이동 가능한 것을 고르면 된다.
각 과정에서 초기화에 유의한다.

주요 알고리즘 : 구현, 브루트 포스, 시뮬레이션

출처 : JDC 2006 D번
*/

int bd[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c, res;

void track(int x, int y, int cnt) {
    int xn, yn;
    if (bd[x][y] == 3) {
        if (cnt < res) res = cnt;
        return;
    }
    if (cnt == 10) return;
    for (int d = 0; d < 4; d++) {
        xn = x, yn = y;
        while (xn >= 0 && yn >= 0 && xn < r && yn < c && bd[xn][yn] != 1) {
            xn += dxy[d][0];
            yn += dxy[d][1];
            if (bd[xn][yn] == 3 && cnt + 1 < res) res = cnt + 1;
        }
        if (xn >= 0 && yn >= 0 && xn < r && yn < c) {
            if (xn - dxy[d][0] != x || yn - dxy[d][1] != y) {
                bd[xn][yn] = 0;
                track(xn - dxy[d][0], yn - dxy[d][1], cnt + 1);
                bd[xn][yn] = 1;
            }
        }
    }
}

int main(void) {
    int xs = -1, ys = -1;
    while (1) {
        scanf("%d %d", &c, &r);
        if (r == 0) break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &bd[i][j]);
                if (bd[i][j] == 2) {
                    xs = i;
                    ys = j;
                }
            }
        }
        res = 103000;
        track(xs, ys, 0);
        printf("%d\n", res == 103000 ? -1 : res);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) bd[i][j] = 0;
        }
    }
    return 0;
}