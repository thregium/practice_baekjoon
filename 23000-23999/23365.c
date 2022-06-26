#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)명의 사람과 그 사람 주변으로 띄워야 하는 거리(<= 10^9)가 주어진다.
이때, 모든 사람을 최적으로 배치했을 때 원형으로 배치하기 위해 필요한 원의 지름을 구한다.
양 옆 사람과의 거리만 고려하고, 거리는 원주를 기준으로 잰다.

해결 방법 : 각 사람의

주요 알고리즘 : 그리디 알고리즘

출처 : BAPC 2021P B번
*/

int main(void) {
    int n, d, hi = 0, lo = INF;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        if (d > hi) hi = d;
        if (d < lo) lo = d;
        r += d;
    }
    r += hi - lo;
    printf("%lld", r);
    return 0;
}