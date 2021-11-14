#include <stdio.h>
#define SZ 1048576

/*
���� : N(N <= 10^6)���� �ڿ����� �̷���� ��������(0���� �ʱ�ȭ�� ����) M(M <= 10^6)���� ������ �����Ѵ�.
0. [A, B]�� ���� ���Ѵ�.
1. A��° ���� B(B <= 100000)�� �ٲ۴�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��
*/

long long seg[SZ * 2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd(int a, int b) {
    seg[a + SZ] = b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, m, o, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &a, &b);
        if (o == 0) {
            if (a > b) swap(&a, &b);
            printf("%lld\n", getsum(a, b, 0, SZ - 1, 1));
        }
        else if (o == 1) {
            upd(a, b);
        }
    }
    return 0;
}