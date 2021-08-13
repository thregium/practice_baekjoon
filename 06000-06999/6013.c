#include <stdio.h>

/*
문제 : 주어진 N(N <= 500)마리의 소들의 좌표가 주어질 때, 가장 멀리 떨어진 한 쌍을 구한다. 거리는 유클리드 거리 기준이고,
가장 멀리 떨어진 쌍은 유일하다.

해결 방법 : 모든 쌍을 비교해서 가장 멀리 떨어진 쌍을 찾으면 된다. 각 쌍의 거리는 피타고라스 정리를 이용한다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : USACO 2009D B2번
*/

int cows[512][2];

int getdist(int a, int b) {
    return (cows[a][0] - cows[b][0]) * (cows[a][0] - cows[b][0]) + (cows[a][1] - cows[b][1]) * (cows[a][1] - cows[b][1]);
}

int main(void) {
    int n, best = 0, a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (getdist(i, j) > best) {
                best = getdist(i, j);
                a = i;
                b = j;
            }
        }
    }
    printf("%d %d", a, b);
    return 0;
}