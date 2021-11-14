#include <stdio.h>
#define MAX 131072

/*
���� : N(N <= 100000)���� �ڿ����� �̷���� �迭�� �־��� ��, M(M <= 100000)���� ���� ������ �����Ѵ�.
1. i��° ���� v�� �ٲ۴�.
2. i��°���� j��°������ �� ��� ¦���� ���� ������ ���Ѵ�.
3. i��°���� j��°������ �� ��� Ȧ���� ���� ������ ���Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��� Ȧ���� ���� ������ �����ϰ� ������Ʈ, �� Ȯ���� �ϸ� �ȴ�.
�Ϲ����� �� ��� 2�� ���� �������� �������ָ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��
*/

long long seg[MAX * 2];

long long sum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return sum(x, y, s, (s + e) >> 1, p << 1) + sum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void update(int a, int b) {
    seg[a + MAX] = b;
    for (int i = (a + MAX) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, q, o, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &seg[i + MAX]);
        seg[i + MAX] &= 1;
    }
    for (int i = MAX - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1) update(x, y & 1);
        else if (o == 2) printf("%lld\n", y - x + 1 - sum(x, y, 0, MAX - 1, 1));
        else printf("%lld\n", sum(x, y, 0, MAX - 1, 1));
    }
    return 0;
}