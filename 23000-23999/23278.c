#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 50)���� ����(0 <=, <= 100, ����)�� �־��� ��, ���� ���� L���� ���� ���� H��(L + H < N)�� ������
������ ����� ���Ѵ�.

�ذ� ��� : �� �������� ������ ����, L + 1��°���� N - H��°������ ���� ���Ѵ�. �� ���� N - L - H�� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����, ����

��ó : TCCC 2007Q1 1��
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, h, s = 0;
    scanf("%d %d %d", &n, &l, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = l; i < n - h; i++) {
        s += a[i];
    }
    printf("%.16f", s / ((double)n - l - h));
    return 0;
}