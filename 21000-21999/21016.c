#include <stdio.h>
#define INF 1012345678
#define SZ 131072

/*
���� : N(N <= 100000)���� ������ �ְ�, M(M <= 100000)���� �����ڰ� �ִ�. �� ������ �ʱ� �ݾ���
a_i(a_i <= 10^9)�̰�, �� �����ڰ� ���ϴ� �ݾ��� b_i(b_i <= 10^9)�̴�.
�� �����ڴ� ���ϴ� �ݾ׺��� ���� ù ���ǿ� ������ �Ѵ�. ������ �� ������ ���ٸ� ������ ���� �ʴ´�.
�̶�, ������ �Ǵ� ������ ������ ���Ѵ�.

�ذ� ��� : �� �����ڰ� ������ ������ ������ ���Ͽ� ���� ã�� �� �ִ�.
�� �����ڰ� ������ ������ ó������ ���� �� �ּڰ��� b_i���� ���� ù ��ġ�� �����̴�.
���ʺ����� �ּڰ��� ���׸�Ʈ Ʈ���� �̺� Ž���� ���� ã�� �� �ִ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, �̺� Ž��

��ó : INC 2020 H��
*/

int a[103000], b[103000], chk[103000], seg[SZ * 2];

int small(int a, int b) {
    return a < b ? a : b;
}

void upd(int p, int x) {
    seg[p + SZ] = x;
    for (int i = (p + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = small(seg[i << 1], seg[(i << 1) + 1]);
    }
}

int getsml(int s, int e, int ss, int se, int p) {
    if (e < ss || se < s) return INF;
    else if (s <= ss && se <= e) return seg[p];
    else return small(getsml(s, e, ss, (ss + se) >> 1, p << 1),
        getsml(s, e, ((ss + se) >> 1) + 1, se, (p << 1) + 1));
}

int main(void) {
    int n, m, lo, hi, mid, r = 0;
    for (int i = 0; i < SZ * 2; i++) seg[i] = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
        seg[i + SZ] = a[i];
    }
    for (int i = SZ - 1; i > 0; i--) seg[i] = small(seg[i << 1], seg[(i << 1) + 1]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        lo = 0, hi = n;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (getsml(0, mid, 0, SZ - 1, 1) < b[i]) hi = mid;
            else lo = mid + 1;
        }
        if (lo == n) continue;
        else {
            r += (!chk[lo]);
            chk[lo] = 1;
            upd(lo, b[i]);
        }
    }
    printf("%d", r);
    return 0;
}