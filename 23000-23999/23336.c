#include <stdio.h>
#define SZ 262144

/*
���� : 1���� N(N <= 200000)������ �ڿ����� �̷���� ������ �ִ�. �� ������ �� ���� 1 ������ ���鳢��
������ �ٲپ� ������ �����ϱ� ���� �ʿ��� ��ȯ Ƚ���� ���Ѵ�.

�ذ� ��� : ��ȣ�� ���� �ٲٸ� ���� ��Ʈ���� �ʿ��� ��ȯ Ƚ���� ����.
�̴� �� ��ġ���� �տ� �ִ� �� ū ���� ������ ����, �̴� ���׸�Ʈ Ʈ���� ���� ������ ã�Ƴ� �� �ִ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��

��ó : TOPC 2021 C��
*/

int a[204800], seg[SZ * 2];

int getsum(int s, int e, int ss, int se, int p) {
    if (e < ss || se < s) return 0;
    if (s <= ss && se <= e) return seg[p];
    else return getsum(s, e, ss, (ss + se) >> 1, p << 1) +
        getsum(s, e, ((ss + se) >> 1) + 1, se, (p << 1) + 1);
}

void upd(int p, int x) {
    seg[p + SZ] += x;
    for (int i = (p + SZ) >> 1; i >= 1; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        r += getsum(a[i] + 1, n, 0, SZ - 1, 1);
        upd(a[i], 1);
    }
    printf("%lld", r);
    return 0;
}