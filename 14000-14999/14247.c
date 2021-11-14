#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)�׷��� ������ �ִ�. �� ������ �ʱ� ���̿� 1�ϴ� �ڶ�� ���̰� �־����ٸ�,
N�ϰ� �ڸ� �� �ִ� ���� ���� ������ ���� ���Ѵ�.

�ذ� ��� : ������ �ڶ�� �� ������� ������ ���� õõ�� �ڸ��� �� ���� �ڸ��� ���� �����̴�.

�ֿ� �˰��� : �׸��� �˰���, ����
*/

int grow[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        r += x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &grow[i]);
    }
    qsort(grow, n, sizeof(int), cmp1);
    for (long long i = 0; i < n; i++) {
        r += grow[i] * i;
    }
    printf("%lld", r);
    return 0;
}