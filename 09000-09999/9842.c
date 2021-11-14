#include <stdio.h>

/*
���� : N(N <= 10000)��° �Ҽ��� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��Ѵ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�

��ó : NOIS 2008 1��
*/

char sieve[131072];
int prime[10240];
int pp = 0;

int main(void) {
    int n;
    for (int i = 2; pp < 10000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j < 131072; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    printf("%d", prime[n - 1]);
    return 0;
}
