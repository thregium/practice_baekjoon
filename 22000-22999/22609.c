#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� �ƴ� ���� N(N <= 100000)�� �ڿ��� P(P <= 100)�� �־��� ��, N���� ū �� �Ҽ��� ��(���� �Ҽ� ����)����
��������� �ڿ��� ��� P��°�� ���� ���� ���� ���Ѵ�.

�ذ� ��� : 100000 ���ķ� 100�� �̻��� �Ǵ� �������� �̸� �����佺�׳׽��� ü�� �̿��� �Ҽ����� ���Ѵ�.
�׸��� N�� P�� �־����� N + 1���� P���� �Ҽ��� ���ؼ� �迭�� �����ϰ�, �ٽ� 2�� for���� ����
��� �Ҽ��� ���� ���Ѵ�. �� ����, ���� ���� �迭�� �����Ͽ� P��° ���� ���ϸ� �װ��� ���� �ȴ�.

�ֿ� �˰��� : ����, ����, �����佺�׳׽�, ����

��ó : JAG 2009D B��
*/

char sieve[103000];
int prime[128], psum[16384];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, p, c;
    sieve[1] = 1;
    for (int i = 2; i <= 103000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 103000; j += i) sieve[j] = 1;
    }
    while (1) {
        scanf("%d %d", &n, &p);
        if (n < 0) break;
        c = 0;
        for (int i = n + 1; c < p; i++) {
            if (!sieve[i]) prime[c++] = i;
        }
        c = 0;
        for (int i = 0; i < p; i++) {
            for (int j = i; j < p; j++) psum[c++] = prime[i] + prime[j];
        }
        qsort(psum, c, sizeof(int), cmp1);
        printf("%d\n", psum[p - 1]);
    }
    return 0;
}