#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * M(N, M <= 50) 크기의 격자에 0과 1이 쓰여 있다.
0이 쓰인 칸 가운데 가장 가까운 1과의 거리가 가장 먼 곳의 거리를 구한다.
거리는 상하좌우대각선으로 이동하는 최단거리를 의미한다.

해결 방법 : 모든 0마다 모든 1에 대해 거리를 구하고 가장 작은 것을 찾으면 된다.
거리는 X와 Y좌표의 절댓값 차이 가운데 더 큰 것을 고르는 것으로 계산 가능하다.

주요 알고리즘 : 수학, 브루트 포스
*/

int a[64][64];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int getdist(int x1, int y1, int x2, int y2) {
    return big(abs(x2 - x1), abs(y2 - y1));
}

int main(void) {
    int n, m, c, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) continue;
            c = 103000;
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) {
                    if (!a[ii][jj]) continue;
                    c = small(c, getdist(i, j, ii, jj));
                }
            }
            r = big(r, c);
        }
    }
    printf("%d", r);
    return 0;
}