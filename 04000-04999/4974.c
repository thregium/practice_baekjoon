#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���� �� �ּڰ��� �ִ��� �� ����� ���Ѵ�. �Ҽ��� �Ʒ��� �����Ѵ�.

�ذ� ��� : ������ ���� ù ���� ������ ���� �� ���� ���� �� N - 2�� ������ �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����, ����, ����

��ó : JDC 2007 A��
*/

int a[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        s = 0;
        for (int i = 1; i < n - 1; i++) s += a[i];
        printf("%d\n", s / (n - 2));
    }
    return 0;
}