#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �Ǽ� ��� 2��°�� ���� ���� ���Ѵ�. ���� ���� �������� �ʴ´�.

�ذ� ��� : ������ ������ ���� 2��° ���� ������ �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : NZPC 2016 A��
*/

double a[128];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    qsort(a, n, sizeof(double), cmp1);
    printf("%.2f", a[1]);
    return 0;
}