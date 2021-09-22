#include <stdio.h>
#include <stdlib.h>

/*
���� : �������� N(N <= 50000)���� ���� �ִ�. �������� �Ÿ� T(T <= 10^9)��ŭ �������� ���� ������ ���� ������ ���Ѵ�.
������ �������� ����� ������� �湮�ؾ� �Ѵ�. �������� �Ÿ��� ���� ���� ���� �� �ִ� ���� ����.

�ذ� ��� : ���������� �Ÿ��� �������� ������ ����, �Ÿ� T�� �� �� ���� �����ϴ� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : USACO 2007N B1��
*/

int lm[51200];

int cmp1(const void* a, const void* b) {
    int ai = abs(*(int*)a);
    int bi = abs(*(int*)b);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, v = 0, p = 0;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lm[i]);
    }
    qsort(lm, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        t -= abs(p - lm[i]);
        p = lm[i];
        if (t < 0) break;
        v++;
    }
    printf("%d", v);
    return 0;
}