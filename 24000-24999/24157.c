#include <stdio.h>
#define INF 1012345678

/*
문제 : N * M(N, M <= 1000) 크기의 정수(-1 <=, <= 100)로 이루어진 배열에서 A * B(A <= N, B <= M) 크기의
직사각형에 쓰인 수의 합이 가장 작은 것의 그 값을 구한다. 단, 중간에 -1이 들어가서는 안 된다.
항상 -1이 들어가지 않고 A * B 크기의 직사각형의 값을 만드는 것이 가능한 경우만 주어진다.

해결 방법 : 2차원 누적 합을 응용해 답을 구할 수 있다. 배열의 -1 개수와 합을 각자
2차원 누적 합으로 만든 다음, 모든 (N - A) * (M - B)개의 직사각형들에 대해 누적 합을 통해
안에 -1이 들어가는 지 여부를 확인한 다음, 들어가지 않는다면 누적 합이 가장 작은 것을 찾아나가면 된다.

주요 알고리즘 : 누적 합

출처 : JOISC 06/07 1-3번
*/

int psum[1024][1024], pops[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int getpop(int x1, int y1, int x2, int y2) {
    return pops[x2][y2] - pops[x1 - 1][y2] - pops[x2][y1 - 1] + pops[x1 - 1][y1 - 1];
}

int main(void) {
    int n, m, a, b, r = INF;
    scanf("%d %d%d %d", &m, &n, &b, &a);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &psum[i][j]);
            if (psum[i][j] < 0) pops[i][j] = pops[i][j - 1] + 1;
            else pops[i][j] = pops[i][j - 1];
            psum[i][j] += psum[i][j - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            psum[j][i] += psum[j - 1][i];
            pops[j][i] += pops[j - 1][i];
        }
    }
    for (int i = 1; i <= n - a + 1; i++) {
        for (int j = 1; j <= m - b + 1; j++) {
            if (getpop(i, j, i + a - 1, j + b - 1) == 0) {
                r = small(r, getsum(i, j, i + a - 1, j + b - 1));
            }
        }
    }
    if (r == INF) return 1;
    printf("%d", r);
    return 0;
}