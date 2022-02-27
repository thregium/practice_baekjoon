#include <stdio.h>

/*
���� : ���� N(N <= 100000)�� �ڿ���(<= 100000)�� �̷���� �迭���� ���� �� �����ϴ� ������ ���̸� ���Ѵ�.

�ذ� ��� : �̺� Ž���� �̿��� ���� �� �ִ�.

�ֿ� �˰��� : �̺� Ž��, LIS

��ó : SEERC 2008 A��
*/

int a[103000], l[103000];

int get_pos(int x, int n) {
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (l[mid] >= x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(void) {
    int n, p, r;
    //freopen("E:\\PS\\ICPC\\Europe\\SEERC\\2008\\input\\a.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\SEERC\\2008\\output\\a_t.out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (r == 0) l[r++] = a[i];
            else {
                p = get_pos(a[i], r);
                if (p == r) l[r++] = a[i];
                else l[p] = a[i];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}