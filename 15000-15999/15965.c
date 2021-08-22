#include <stdio.h>

/*
���� : N(N <= 500000)��° �Ҽ��� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��Ѵ�.

�ֿ� �˰��� : ����, �����佺�׳׽��� ü 

��ó : BSIS D��
*/

char sieve[8388608];
int primes[524288];
int pp = 0;

int main(void) {
    int n;
    for (int i = 2; i < 7654321; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i << 1; j < 7654321; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    printf("%d", primes[n - 1]);
    return 0;
}