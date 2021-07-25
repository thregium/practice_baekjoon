#include <stdio.h>

/*
문제 : N(N <= 100000)일간 M(M <= 10)가지 간식 중 하나를 먹는다. 각 간식을 특정한 날 먹을 때의 행복도가 각각 주어진다.
이때, 전날 먹었던 간식과 같은 간식을 먹으면 그 날 얻을 수 있는 행복도가 절반이 된다면, 간식을 특정한 순서로 먹어서
행복도를 최대로 맞추었을 때 얻을 수 있는 행복도를 구한다.

해결 방법 : 모든 날에 대해 각 간식을 마지막으로 먹었을 때의 행복도를 저장해둔다. 그리고 매일 각 간식을 먹었을 때의
최대 행복도를 이전 날의 간식 가운데 오늘 간식을 추가했을 때의 행복도를 비교해 구할 수 있다.
이를 반복해 N일까지 간 다음 N일째의 행복도 가운데 가장 높은 것을 고르면 된다.

주요 알고리즘 : DP

출처 : 한양대 6회 AE, BK번
*/

int dess[103000][16], mem[103000][16];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &dess[j][i]);
        }
    }
    for (int i = 0; i < m; i++) mem[1][i] = dess[1][i];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                mem[i][j] = big(mem[i][j], mem[i - 1][k] + (j == k ? (dess[i][j] >> 1) : dess[i][j]));
            }
        }
    }
    for (int i = 0; i < m; i++) {
        r = big(r, mem[n][i]);
    }
    printf("%d", r);
    return 0;
}