#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� ����(<= 1000, �ڿ���)�� �־��� ��,
�־��� ���� B(B <= 100000)���� �� �� �ִ� ������ �ִ� ������ ���Ѵ�.

�ذ� ��� : ���� �� �� ���� ������ ��, �� ������� �ִ��� �纸�� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : GKS 2020A A��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, b, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &b);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= b) {
                b -= a[i];
                r++;
            }
            else break;
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}