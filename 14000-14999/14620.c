#include <stdio.h>

/*
문제 : N * N(N <= 10) 크기의 격자에서 십자 모양을 겹치지 않게 3개 놓고, 이 놓은 곳의 값의 합을 가장 작게 할 때, 그 값을 구한다.

해결 방법 : 모든 칸에 대해 각각 겹치지 않게 놓아보며 합이 가장 작은 값을 찾는다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : 인하대 2017 J번
*/

int g[16][16], s[16][16];
int dxy[5][2] = { {0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, best = 12345;

track(int a, int x, int m) {
    if (a == x) {
        if (m < best) best = m;
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (s[i][j] || s[i][j - 1] || s[i - 1][j] || s[i][j + 1] || s[i + 1][j]) continue;
            for (int k = 0; k < 5; k++) {
                s[i + dxy[k][0]][j + dxy[k][1]] = 1;
                m += g[i + dxy[k][0]][j + dxy[k][1]];
            }
            track(a, x + 1, m);
            for (int k = 0; k < 5; k++) {
                s[i + dxy[k][0]][j + dxy[k][1]] = 0;
                m -= g[i + dxy[k][0]][j + dxy[k][1]];
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    track(3, 0, 0);
    printf("%d", best);
    return 0;
}