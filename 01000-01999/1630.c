#include <stdio.h>
#define MOD 987654321

/*
���� : N(N <= 10^6) ������ ��� �ڿ����� ������ �������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� N ������ ��� �Ҽ��� ���� ����, N ������ ��� �Ҽ��� ����
N���� �����鼭 ���� ū �ش� �Ҽ��� �ŵ������� ��� ���� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�
*/

char sieve[1048576];
int prime[131072];
int pp = 0;

int main(void) {
    int n;
    long long r = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < pp; i++) {
        for (int j = n / prime[i]; j; j /= prime[i]) r = (r * prime[i]) % MOD;
    }
    printf("%lld", r);
    return 0;
}