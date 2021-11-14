#include <stdio.h>
#define SZ 131072

/*
���� : N(N <= 100000)���� ������ �̷���� ������ �־��� ��, K(K <= 100000)���� ������ �����Ѵ�.
C: i��° ���� X�� �ٲ۴�.
P: i��°���� j��° �������� ���� 0���� �������� ������� ���Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ�� 2���� �̿��ؼ� �Ѱ��� �� ������ ������ ������ �����ϰ�, �Ѱ��� 0�� ������ �����Ѵ�.
P�� ���� �� ���� �ش� ������ ���� Ȯ���ؼ� 0�� �ϳ��� ������ 0�� ����ϰ�, �� �ܿ��� ������ ������ ����
Ȧ���� ������ ����, ¦���� ������ ����� ����Ѵ�. C�� ���� ������ ������ ���� ���� ������
��츦 �з��ؼ� ������ 0�� ������ �ٲپ� �ָ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��

��ó : Latin 2012 I��
*/

int seg[SZ * 2], seg2[SZ * 2];

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

long long getsum2(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg2[p];
    return getsum2(x, y, s, (s + e) >> 1, p << 1) + getsum2(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd2(int a, int b) {
    seg2[a + SZ] = b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg2[i] = seg2[i << 1] + seg2[(i << 1) + 1];
    }
}

int main(void) {
    int n, k, x, y;
    char o;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == 0) upd2(i, 1);
            else upd2(i, 0);
            if (x < 0) upd(i, 1);
            else upd(i, 0);
        }
        for (int i = 0; i < k; i++) {
            scanf(" %c %d %d", &o, &x, &y);
            if (o == 'C') {
                if (y < 0) upd(x, 1);
                else upd(x, 0);
                if (y == 0) upd2(x, 1);
                else upd2(x, 0);
            }
            else if (o == 'P') {
                if (getsum2(x, y, 0, SZ - 1, 1) > 0) printf("0");
                else if (getsum(x, y, 0, SZ - 1, 1) & 1) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}