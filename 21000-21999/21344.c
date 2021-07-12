#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ �־��� ��, �� ������ ������ �� ���� ���̰� �پ���� �ʴ� ������ ��ġ�Ѵ�.

�ذ� ��� : ������ ������ ��, ��� ��ġ���� ������� ������ �ٱ������� ���ʷ� ������ָ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : NWERC 2020 H��
*/

int t[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s, d = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), cmp1);
    s = ((n - 1) >> 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", t[s]);
        if (d & 1) s += d;
        else s -= d;
        d++;
    }
    return 0;
}