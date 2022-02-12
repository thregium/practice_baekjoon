#include <stdio.h>

/*
문제 : N * N(N <= 300) 크기의 격자에서 해당 칸의 이익(|| <= 1000)이 주어진다.
이때, 정사각형 범위 가운데 이익이 가장 큰 범위를 구한다. 단, 범위가 0일 수는 없다.

해결 방법 : 2차원 누적 합을 미리 구해두면 각 정사각형 범위마다의 이익을 O(1)에 구할 수 있다.
정사각형 범위의 개수가 O(N^3)이므로 모든 정사각형 범위마다 이익을 누적 합으로 구해서 가장 큰 것을 구하면 된다.

주요 알고리즘 : 브루트 포스, 누적 합

출처 : 충남대 4회 B번
*/

int psum[384][384];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int main(void) {
    int n, r = -103000;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &psum[i][j]);
            psum[i][j] += psum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) psum[j][i] += psum[j - 1][i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= small(n - i + 1, n - j + 1); k++) {
                r = big(r, getsum(i, j, i + k - 1, j + k - 1));
            }
        }
    }
    printf("%d", r);
    return 0;
}