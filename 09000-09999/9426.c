#include <stdio.h>
#define SZ 262144

/*
���� : ���� N(N <= 250000)�� 65535 ���� ���� �ƴ� ������ �̷���� ������ �־��� ��,
�� ������ ��� ������ K�� ���� �߾Ӱ��� ���� ���Ѵ�. K�� ¦���� ��� �߾Ӱ��� K / 2��° ���̴�.

�ذ� ��� : ���׸�Ʈ Ʈ���� ���� ���� �κ��� ������ ������ �����Ѵ�.
�׸���, �Ű� ���� Ž���� ���� ���� ���� ceil(K / 2)�� �̻��� ���� ���� ���� ã���� �߾Ӱ��̹Ƿ�,
�̸� �ݺ��� ������ �߾Ӱ����� ã�Ƽ� ���س����� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, �Ķ��Ʈ��
*/

int a[SZ], seg[SZ * 2];

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
    int n, k, lo, hi, mid;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        upd(a[i], 1);
    }
    for (int i = 0; i <= n - k; i++) {
        lo = 0, hi = 65535;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (getsum(0, mid, 0, SZ - 1, 1) >= ((k + 1) >> 1)) hi = mid;
            else lo = mid + 1;
        }
        //printf("#%d\n", lo);
        r += lo;
        upd(a[i + k], 1);
        upd(a[i], -1);
    }
    printf("%lld", r);
    return 0;
}