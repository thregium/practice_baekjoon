#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �ڿ���(<= 10^6)�� �־��� ��, ������ �־��� ������� ����Ѵ�.

�ذ� ��� : �迭�� ������ ����, Ȧ���� ¦����°�� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : CCC 2017 S2��
*/

int a[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i & 1) printf("%d ", a[(n + i) >> 1]);
        else printf("%d ", a[(n - i - 1) >> 1]);
    }
    return 0;
}