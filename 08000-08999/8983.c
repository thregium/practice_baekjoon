#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
���� : �������� M(M <= 100000)���� ���� �ְ�, ��ǥ��� �� N(N <= 100000)���� ���� �ִ�. ��ǥ����� �� ���
�ϳ� �̻��� ���������� ���� �Ÿ��� L(L <= 10^9) ������ ���� ������ ���Ѵ�. ��, ��� ��ǥ�� 10^9 ������ �ڿ����̴�.

�ذ� ��� : �������� ��ǥ������ ������ X���� �������� ������ �� ��ǥ������ ������ X��ǥ ���� ���ʿ� �ִ� ������ ��ǥ��
���ؼ� �� �� �Ÿ��� �� ���� ���� �Ÿ��� L ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : ���� 2013 ��1/��1��
*/

int sa[103000], ani[103000][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getdist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
    int m, n, l, dist, p = 0, r = 0;
    scanf("%d %d %d", &m, &n, &l);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sa[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &ani[i][0]);
        scanf("%d", &ani[i][1]);
    }
    qsort(sa, m, sizeof(int), cmp1);
    qsort(ani, n, sizeof(int) * 2, cmp1);
    sa[m] = 1012345678;
    for (int i = 0; i < n; i++) {
        while (ani[i][0] > sa[p]) p++;
        if (p == 0) dist = getdist(ani[i][0], ani[i][1], sa[p], 0);
        else if (p == m) dist = getdist(ani[i][0], ani[i][1], sa[p - 1], 0);
        else dist = small(getdist(ani[i][0], ani[i][1], sa[p - 1], 0), getdist(ani[i][0], ani[i][1], sa[p], 0));
        if (dist <= l) r++;
    }
    printf("%d", r);
    return 0;
}
