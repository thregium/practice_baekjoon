#include <stdio.h>
#define SZ 1048576

/*
���� : ���� N(N <= 10^6)�� 0���� �ʱ�ȭ�� �迭�� �־��� ��, Q(Q <= 100000)���� ������ �����Ѵ�.
1. �迭�� P��° ���� X(|X| <= 2 * 10^9)�� ���Ѵ�.
2. �迭�� P��°���� Q��°���� ���� ���� ���Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��
*/

long long seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd(int a, int b) {
    seg[a + SZ] += b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, q, o, x, y;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1) upd(x, y);
        else printf("%lld\n", getsum(x, y, 0, SZ - 1, 1));
    }
    return 0;
}