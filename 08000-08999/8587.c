#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

/*
���� : N(N <= 10^6)���� �������� �ִ�. �� �������� ũ�Ⱑ N ������ ��, 1���� N������ ũ����
������ ���� 1���� �ִٸ�, �����Կ� �������� ��� �ִ� ����� ���� ���� ���Ѵ�.

�ذ� ��� : �� �������� ũ�⸦ ������������ �����Ѵ�. ���� ���� ������ �ּ� ũ�⺸�� �������� ũ�Ⱑ
���� ���� �ִ� ��쿡�� ���� 0�� �ȴ�. �׷��� ���� ���ٸ� �� �����Կ� �ִ� ����� ����
������ �ּ� ũ����� ���̿� ����. ���� �� ������ ��� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ����

��ó : JPOI 2011 2-1��
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) r = 0;
        else r = (r * (a[i] - i)) % MOD;
    }
    printf("%lld", r);
    return 0;
}