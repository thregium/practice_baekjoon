#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 100000)���� �������� ���۰� ������ �־��� ��, �� �����ٵ��� ������ �ʵ��� ����� ����
�����ؾ� �ϴ� �������� �ּ� ������ �׷��� �����ٵ��� ����� ����Ѵ�.

�ذ� ��� : LIS�� �̺� Ž���� �̿��� ���� ����, LIS�� �ƴ� ���� ã���� �ȴ�.

�ֿ� �˰��� : �̺� Ž��, LIS

��ó : ���� 2007�� ��3��
*/

int elec[103000][3], a[103000][2], lis[103000][2], res[103000], res2[103000], levels[103000];
int liz = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, l, s = 0, p = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &elec[i][0], &elec[i][1]);
        elec[i][2] = i + 1;
    }
    qsort(elec, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        a[i][0] = elec[i][1];
        if (a[i][0] > (liz ? lis[liz - 1][0] : -INF)) {
            lis[liz][0] = a[i][0];
            levels[liz] = i;
            a[i][1] = liz ? levels[liz - 1] : -1;
            s = i;
            liz++;
        }
        else {
            h = liz - 1;
            l = 0;
            while (h > l) {
                if (a[i][0] > lis[(h + l) >> 1][0]) l = ((h + l) >> 1) + 1;
                else h = (h + l) >> 1;
            }
            if (h >= 0) {
                lis[h][0] = a[i][0];
                levels[h] = i;
                a[i][1] = h ? levels[h - 1] : -1;
            }
        }
    }
    for (int i = liz - 1; i >= 0; i--) {
        res[i] = a[s][0];
        s = a[s][1];
    }
    for (int i = 0; i < n; i++) {
        if (!bsearch(&elec[i][1], res, liz, sizeof(int), cmp1)) {
            res2[p++] = elec[i][0];
        }
    }
    if (p != n - liz) return 1;
    printf("%d\n", n - liz);
    qsort(res2, p, sizeof(int), cmp1);
    for (int i = 0; i < p; i++) {
        printf("%d\n", res2[i]);
    }
    return 0;
}