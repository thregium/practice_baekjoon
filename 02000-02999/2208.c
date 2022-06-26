#include <stdio.h>
#define SZ 131072

/*
���� : N(N <= 100000)���� ������ �Ϸķ� �ִ�. M(M <= N)�� �̻��� ���ӵ� ������ �� �ѹ���
�ֿ� �� �ִٸ� ���� �� �ִ� ������ �ִ��� ���Ѵ�. ������ ���� ���� �� �ְ�,
������ ������ 2000 ���ϴ�.

�ذ� ��� : ���� ���� ���� �� ����(0��° ����)���� �� ���� + M��°���� ������ ���� ���� �� ���� ���� �ִ�
�� ���̸� ���� ���ϰ�, �� �� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, ���� ��
*/

int gem[103000], seg[SZ << 1];

int big(int a, int b) {
    return a > b ? a : b;
}

long long seg_query(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return -1012345678;
    if (x <= s && y >= e) return seg[p];
    return big(seg_query(x, y, s, (s + e) >> 1, p << 1), seg_query(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1));
}

int main(void) {
    int n, m, res = 0, tres;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < SZ * 2; i++) seg[i] = -1012345678;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &gem[i]);
        gem[i] += gem[i - 1];
        seg[SZ + i] = gem[i];
    }
    for (int i = SZ - 1; i >= 1; i--) {
        seg[i] = big(seg[i << 1], seg[(i << 1) + 1]);
    }
    for (int i = 0; i <= n - m; i++) {
        tres = seg_query(i + m, n, 0, SZ - 1, 1) - gem[i];
        if (tres > res) res = tres;
    }
    printf("%d", res);
    return 0;
}