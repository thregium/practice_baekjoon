#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10^6)���� �ڿ���(<= 100000) ��� K(K <= N)��°�� ���� ���� ���Ѵ�. �ߺ��� �����Ѵ�.

�ذ� ��� : ������ ������ ����, K - 1�� ���Ҹ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : AMPPZ 2007 I��
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        printf("%d\n", a[k - 1]);
    }
    return 0;
}