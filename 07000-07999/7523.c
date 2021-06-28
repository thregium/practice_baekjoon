#include <stdio.h>

/*
문제 : N부터 M(-10^9 <= N <= M <= 10^9)까지 정수의 합을 구한다.

해결 방법 : 가우스 합 공식을 이용한다.

주요 알고리즘 : 수학

출처 : TUD 2006 8번
*/

long long getsum(long long s, long long e) {
    return ((s + e) * (e - s + 1)) >> 1;
}

int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        printf("Scenario #%d:\n", tt);
        printf("%lld\n\n", getsum(n, m));
    }
    return 0;
}