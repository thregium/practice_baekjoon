#include <stdio.h>
#define MOD 1000000007

/*
���� : �� �ڿ��� N, M(N, M <= 15 * 10^6)�� �־��� ��, (1, 1)�� (N, M) ���� ��� �����ֿ� ���� GCD�� ���� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��Ͽ� N �Ǵ� M ���̿� �ִ� ��� �Ҽ��� ���� ����,
�׷��� �Ҽ��鸶�� ������ ���� ������ ���ϰ�, �� ������ ���� ���� �ŵ������� ���ؼ� �Ź� �����ָ� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, ���� �ŵ�����
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