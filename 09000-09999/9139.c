#include <stdio.h>
#define SZ 131072

/*
���� : ���� N(N <= 100000)�� 1���� N������ �ڿ����� �̷���� ������ �־��� ��,
�� ������ 1���� N���� ���ʷ� �ö󰡴� �������� ���� �ٸ� 3���� �� (a, b, c)�� ����
������ (c, a, b)�� �ٲٴ� ������ �ݺ��Ͽ� ���� �� �ִ� �� ���Ѵ�.

�ذ� ��� : �� �ڸ������� ���� �� �ִ� �ش� ������ ���� ���� �������� ���� ���� ���� Ȧ���� ���
�׷��� ������ ���� �� ����, ¦���� ��� ���� �� �ִ�.
�̴� ���׸�Ʈ Ʈ���� ���� �� �ڸ����� �տ� �ִ� ���� ������� ���� ���� ������ Ȯ���Ͽ� ���� �� �ִ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��

��ó : CTU 2001 E��
*/

int a[103000], seg[SZ * 2];

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
    int n;
    long long r;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\e.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\e_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) upd(i, 1);
        r = 0;
        for (int i = 1; i <= n; i++) {
            r += getsum(1, a[i] - 1, 0, SZ - 1, 1);
            upd(a[i], 0);
        }
        if (r & 1) printf("Matfyzacci maji smulu.\n");
        else printf("Permutaci lze prevest.\n");
    }
    return 0;
}