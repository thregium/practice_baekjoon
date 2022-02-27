#include <stdio.h>
#include <stdlib.h>
#define SZ 131072

/*
���� : ���� N(N <= 100000)�� N ������ �ڿ����� �̷���� ���� A�� �־��� ��,
�� �������� i < j < k�̸� A_i > A_j > A_k�� �������� ������ ���Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��Ͽ� �� j������ (i, j) �������� ������ ���ϰ�,
���� ������� (i, j, k) �������� ������ ���ϸ� �ȴ�. (i, j) �������� �տ� ���� ���� ���
���� ������ ū ���� ������ ���ϴ� ������� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��

��ó : NCPC 2011 B��
*/

long long a[103000], mem[16][103000], seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return (getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1));
}

void upd(int a, int b) {
    seg[a + SZ] = (seg[a + SZ] + b);
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = (seg[i << 1] + seg[(i << 1) + 1]);
    }
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        //a[i] = rand() % 100;
        scanf("%lld", &a[i]);
        mem[1][i] = 1;
    }
    for (int i = 2; i <= 3; i++) {
        for (int j = 0; j < SZ * 2; j++) seg[j] = 0;
        for (int j = 1; j <= n; j++) {
            mem[i][j] = getsum(a[j] + 1, SZ - 1, 0, SZ - 1, 1);
            upd(a[j], mem[i - 1][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        r = (r + mem[3][i]);
    }
    printf("%lld", r);
    return 0;
}