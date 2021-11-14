#include <stdio.h>
#define MOD 123456789

/*
���� : �ڿ��� N(N <= 40000)�� ���� �Ҽ��� ������ N�� ����� ����� �������� ���Ѵ�. ������ ������� �ʴ´�.

�ذ� ��� : 40000 ������ �Ҽ��� ��� ���� ����, ������ ���� N�� ����� ����� �������� ���ϸ� �ȴ�.
���� �Ҽ��� ���� �� �� �� ������ ���� Ƚ���� ������ �����Ѵ�.

�ֿ� �˰��� : DP, ����, �����佺�׳׽�

��ó : ȫ�ʹ� 2018 G��
*/

char sieve[40960];
int prime[5120], mem[40960];
int pp = 0;

int main(void) {
    int n;
    for (int i = 2; i <= 40000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 40000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    mem[0] = 1;
    for (int i = 0; i < pp; i++) {
        if (prime[i] > n) break;
        for (int j = 0; j <= n; j++) {
            if (j < prime[i]) mem[j] = mem[j];
            else mem[j] = (mem[j] + mem[j - prime[i]]) % MOD;
        }
    }
    printf("%d", mem[n]);
    return 0;
}