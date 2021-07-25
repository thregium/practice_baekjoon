#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� �� H�� �̻��� ���� H�� �̻��� ���� ū H�� ���Ѵ�.

�ذ� ��� : ������ ������ ����, 0�� N���� ������ �Ű� ���� Ž���� �����Ѵ�. i - 1��° �迭�� ���� i �̻������� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ����, �̺� Ž��

��ó : Rocky 2018 D��
*/

int c[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, lo, hi;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    lo = 0, hi = n;
    while (lo < hi) {
        if (c[((lo + hi + 1) >> 1) - 1] >= ((lo + hi + 1) >> 1)) lo = (lo + hi + 1) >> 1;
        else hi = ((lo + hi + 1) >> 1) - 1;
    }
    printf("%d", hi);
    return 0;
}