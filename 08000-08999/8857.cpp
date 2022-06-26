#include <stdio.h>

/*
문제 : N(N <= 45)개의 비트로 이루어진 1로 시작하며 연속한 1이 없는 수의 개수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 이용한다. 끝이 0일때와 1일 때로 나누면
답은 피보나치 수열과 같음을 알 수 있다.

주요 알고리즘 : DP

출처 : SKI 2010 1-1번
*/

long long fib[64];

int main(void) {
    int t, n;
    fib[1] = 1, fib[2] = 1;
    for (int i = 3; i <= 45; i++) fib[i] = fib[i - 1] + fib[i - 2];
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%lld\n", fib[n]);
    }
    return 0;
}