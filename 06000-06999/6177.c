#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 500)���� ���� X_i(|X_i| <= 5000)�� ���� ��հ� �߾Ӱ��� ���Ѵ�. N�� ¦���� ��� �߾Ӱ��� ��� �� ���� ����̴�.

�ذ� ��� : N���� �� ���� ���� ���� N���� ���� ���� ����� �ǰ�, �߾Ӱ��� N���� ���� ������ ����
��� ��(N�� Ȧ���� ���, N / 2) �Ǵ� ��� �� ��(¦���� ���, N / 2 - 1, N / 2)�� ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ����

��ó : USACO 2008M B1��
*/

int a[512];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    printf("%.9f\n", (double)s / n);
    if (n & 1) printf("%d", a[n >> 1]);
    else printf("%.9f", (a[n >> 1] + a[(n >> 1) - 1]) / 2.0);
    return 0;
}