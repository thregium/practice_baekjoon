#include <stdio.h>
#define INF 1012345678
#define SZ 131072

/*
���� : N(N <= 100000)���� 10^9 ������ �ڿ����� �̷���� �������� M(M <= 100000)���� ������ �����Ѵ�.
1. X��° �ڿ����� Y�� �ٲ۴�.
2. [X, Y] ������ �ִ� �ڿ��� ��� ���� ���� �ڿ��� �� ���� ���ʿ� �ִ� �ڿ����� ��ȣ�� ���Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��Ѵ�. ������ ����� ��쿡 �����Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��
*/

int a[SZ], seg[SZ * 2];

long long getsmall(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    int l = getsmall(x, y, s, (s + e) >> 1, p << 1);
    int r = getsmall(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
    if (a[l] <= a[r]) return l;
    else return r;
}

void upd(int x, int y) {
    a[x] = y;
    for (int i = (x + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = a[seg[i << 1]] <= a[seg[(i << 1) + 1]] ? seg[i << 1] : seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, m, o, x, y;
    scanf("%d", &n);
    for (int i = 0; i < SZ; i++) {
        a[i] = INF;
        seg[SZ + i] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = SZ - 1; i >= 1; i--) {
        seg[i] = a[seg[i << 1]] <= a[seg[(i << 1) + 1]] ? seg[i << 1] : seg[(i << 1) + 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1) upd(x, y);
        else printf("%lld\n", getsmall(x, y, 0, SZ - 1, 1));
    }
    return 0;
}