#include <stdio.h>

/*
문제 : N(N <= 200000)의 제곱의 양의 배수 중 가장 작은 것을 구한다.

해결 방법 : N의 제곱에 1을 곱하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : Manila 2016 PA번
*/

int main(void) {
    long long t, n;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        printf("%lld\n", n * n);
    }
    return 0;
}