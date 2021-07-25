#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10)개의 정사각형 형태의 타일을 적절히 바꾸어 넓이의 합이 M(M <= 10000) 이하가 되도록 만들려고 한다.
각 타일을 바꾸는데 드는 비용은 (A_i - M)^2이라고 할 때, 최소한으로 필요한 비용을 구한다. 불가능한 경우 -1을 출력한다.
각 타일의 한 변은 항상 자연수 길이가 되어야 한다.

해결 방법 : i번째의 타일까지 확인했을 때 각 넓이별로 필요한 최소 비용을 구한다. 불가능한 경우는 무한대로 초기화한다.
각 넓이마다 현재 타일을 모든 크기로 변환하며 가장 비용이 적은 것을 고르면 된다.

주요 알고리즘 : DP, 냅색 문제

출처 : USACO 2011N S3번
*/

int a[16], mem[16][10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) mem[0][i] = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            mem[i][j] = INF;
            for (int k = 1; k * k <= j; k++) {
                mem[i][j] = small(mem[i][j], mem[i - 1][j - k * k] + (a[i] - k) * (a[i] - k));
            }
        }
    }
    if (mem[n][m] == INF) {
        printf("-1");
    }
    else printf("%d", mem[n][m]);
    return 0;
}