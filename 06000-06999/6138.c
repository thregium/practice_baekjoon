#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선상에 N(N <= 50000)개의 점이 있다. 원점에서 거리 T(T <= 10^9)만큼 움직여서 도달 가능한 점의 개수를 구한다.
점들은 원점에서 가까운 순서대로 방문해야 한다. 원점에서 거리가 같은 점이 여러 개 있는 경우는 없다.

해결 방법 : 원점에서의 거리를 기준으로 정렬한 다음, 거리 T가 될 때 까지 도달하는 점의 개수를 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 정렬

출처 : USACO 2007N B1번
*/

int lm[51200];

int cmp1(const void* a, const void* b) {
    int ai = abs(*(int*)a);
    int bi = abs(*(int*)b);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, v = 0, p = 0;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lm[i]);
    }
    qsort(lm, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        t -= abs(p - lm[i]);
        p = lm[i];
        if (t < 0) break;
        v++;
    }
    printf("%d", v);
    return 0;
}