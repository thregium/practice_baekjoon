#include <stdio.h>
#define MOD 1000000007

/*
문제 : 두 자연수 N, M(N, M <= 15 * 10^6)이 주어질 때, (1, 1)과 (N, M) 사이 모든 순서쌍에 대한 GCD의 곱을 구한다.

해결 방법 : 에라토스테네스의 체를 이용하여 N 또는 M 사이에 있는 모든 소수를 구한 다음,
그러한 소수들마다 순서쌍 내의 개수를 구하고, 그 값들을 각각 분할 거듭제곱을 통해서 매번 곱해주면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 분할 거듭제곱
*/

char sieve[16777216];

long long sqr(long long n) {
    return n * n % MOD;
}

long long mult(long long n, long long m) {
    if (m == 0) return 1;
    else if (m == 1) return n;
    if (m & 1) return (sqr(mult(n, m >> 1)) * n) % MOD;
    else return sqr(mult(n, m >> 1));
}

int main(void) {
    int n, m;
    long long r = 1;
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= n; j += i) sieve[j] = 1;
    }
    for (long long i = 2; i <= n; i++) {
        if (sieve[i]) continue;
        for (long long a = n, b = m; a && b; a /= i, b /= i) {
            r *= mult(i, (a / i) * (b / i));
            r %= MOD;
        }
    }
    printf("%lld", r);
    return 0;
}