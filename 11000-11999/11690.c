#include <stdio.h>

/*
���� : 1���� N(N <= 10^8)������ ���� �ּҰ������ ���Ѵ�.

�ذ� ��� : 1���� 1������� ���� ��Ʈ ������ ���·� ǥ���� �� �����佺�׳׽��� ü�� ����Ѵ�.
�� ����, N ������ ��� �Ҽ��� ���� N ������ ���� ū �Ҽ��� �ŵ������� ���س����� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, ��Ʈ ����
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