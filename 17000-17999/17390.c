#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 300000)���� �ڿ����� �̷���� �迭�� �־��� ��, �� �迭�� �񳻸��������� ������ ��,
Q(Q <= 300000)���� ������ �����Ѵ�.
L��°���� R��°������ ���� ���� ���Ѵ�.

�ذ� ��� : �迭�� ������ ����, ���� ���� �̿��� ������ �����Ѵ�.

�ֿ� �˰��� : ���� ��, ����

��ó : ������ 2019 C��
*/

int a[327680];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, q, s, e;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n, sizeof(int), cmp1);
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", a[e] - a[s - 1]);
    }
    return 0;
}