#include <stdio.h>
#define INF 42933964230

/*
문제 : N(N <= 2000)개의 점들이 있고, 각각의 좌표는 100000 이하의 자연수이다. 이때, 가장 가까운 두 점의 쌍을 구한다.
가장 가까운 쌍은 유일하다.

해결 방법 : 피타고라스의 정리를 이용해 모든 쌍의 거리를 살펴본 다음, 가장 가까운 쌍을 찾으면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : USACO 2009N B1번
*/

int coord[2048][2];

long long sqr(long long x) {
    return x * x;
}

long long getdist(int a, int b) {
    return sqr(coord[a][0] - coord[b][0]) + sqr(coord[a][1] - coord[b][1]);
}

int main(void) {
    int n, b1 = -1, b2 = -1;
    long long best = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &coord[i][0], &coord[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (getdist(i, j) < best) {
                best = getdist(i, j);
                b1 = i;
                b2 = j;
            }
        }
    }
    if (b1 < 0) return 1;
    printf("%d %d", b1, b2);
    return 0;
}