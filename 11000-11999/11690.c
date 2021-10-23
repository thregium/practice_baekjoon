#include <stdio.h>

/*
문제 : 1부터 N(N <= 10^8)까지에 대한 최소공배수를 구한다.

해결 방법 : 1부터 1억까지의 수를 비트 집합의 형태로 표현한 후 에라토스테네스의 체를 사용한다.
그 다음, N 이하의 모든 소수에 대해 N 이하의 가장 큰 소수의 거듭제곱을 곱해나가면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 비트 집합
*/

char sieve[12800000];

int main(void) {
    int n;
    unsigned int r = 1;
    scanf("%d", &n);
    for (long long i = 2; i <= n; i++) {
        if (sieve[i >> 3] & (1 << (i & 7))) continue;
        for (long long j = i * 2; j <= n; j += i) {
            sieve[j >> 3] |= (1 << (j & 7));
        }
    }
    for (long long i = 2; i <= n; i++) {
        if (sieve[i >> 3] & (1 << (i & 7))) continue;
        for (long long x = n; x >= i; x /= i) r *= i;
    }
    printf("%u", r);
    return 0;
}