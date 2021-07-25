#include <stdio.h>

/*
문제 : N(N <= 10)개의 속력과 도착 시각 기록이 주어질 때, 전체 이동 거리를 구한다.

해결 방법 : 해당 구간동안 달린 거리는 (마지막 시각 - 그 전 시각) * 속력이다. 이들의 합을 구하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : MidC 2004 G번
*/

int main(void) {
    int n, s, t, lt, r = 0;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        lt = 0, r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &s, &t);
            r += s * (t - lt);
            lt = t;
        }
        printf("%d miles\n", r);
    }
    return 0;
}