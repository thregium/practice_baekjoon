#include <stdio.h>
#define SZ 131072

/*
���� : N(N <= 100000)���� ���� �̷���� ������ �־��� ��, ���� ������ �����Ѵ�.
1. L��°���� R��°������ ������ �񳻸��������� Ȯ���Ѵ�.
2. L��°�� R��°�� ���� �ٲ۴�.

�ذ� ��� : L��°���� R��°������ ������ �񳻸������� ���� L��°�� R��° ������ ��� ������ ������ ���� ���ų�
������ ���� �� ū ����̴�. �̴� ��� ĭ�� ���� ������ ���� ���� ������ ���� ���ų� ū ���� ������ ���� ����
L��°�� R��° ������ �������� R - L�� ������ Ȯ������ ���� �ذ� �����ϴ�.
�� ������ ���׸�Ʈ Ʈ���� �̿��ϸ� ���� �� �� �ִ�.

L��°�� R��°�� ���� �ٲٴ� ������ ������ ���� �ٲ���� ����, �ش� �� �ֺ� ĭ�� ���ؼ� �ֺ��� ���� ��������
������Ʈ �ϴ� ������� ���� �����ϴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��

��ó : KAIST 2016S B��
*/

int a[SZ], seg[SZ * 2];

void upd(int x, int y) {
    seg[SZ + x] = y;
    for (int i = (SZ + x) >> 1; i; i >>= 1) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
}

int find(int l, int r, int sl, int sr, int p) {
    if (r < sl || sr < l || l > r) return 0;
    if (l <= sl && sr <= r) return seg[p];
    return find(l, r, sl, (sl + sr) >> 1, p << 1) + find(l, r, ((sl + sr) >> 1) + 1, sr, (p << 1) + 1);
}

int main(void) {
    int n, xy, q, l, r, t;
    scanf("%d %d", &n, &xy);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= a[i - 1]) upd(i - 1, 1);
    }
    for (int i = 0; i < xy; i++) {
        scanf("%d %d %d", &q, &l, &r);
        if (q == 1) {
            if (find(l, r - 1, 0, SZ - 1, 1) == r - l) printf("CS204\n");
            else printf("HSS090\n");
        }
        else {
            t = a[l];
            a[l] = a[r];
            if (a[l] >= a[l - 1]) upd(l - 1, 1);
            else upd(l - 1, 0);
            if (a[l + 1] >= a[l]) upd(l, 1);
            else upd(l, 0);
            a[r] = t;
            if (a[r] >= a[r - 1]) upd(r - 1, 1);
            else upd(r - 1, 0);
            if (a[r + 1] >= a[r]) upd(r, 1);
            else upd(r, 0);
        }
    }
    return 0;
}