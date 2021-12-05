#include <stdio.h>
#define SZ 262144

/*
���� : 1���� N(N <= 100000)������ �ڿ����� ���ʷ� �ִ� ����� �־��� ��,
M(M <= 100000)���� ���� ���ʷ� �� ������ �ű�� �������� �ش��ϴ� ���� �տ� �ִ� ������ ���ʷ� ����Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��ؼ� ���� ��忡�� �� ��ġ���� ���� �ִ��� ���θ� �����Ѵ�.
�׷��� 0�� ������ p - 1(p�� �ش� ���� ��ġ)�� ������ ���Ǵ� ������ ���� �� ������ �� �� �ִ�.
������ Ȯ���� �������� p�� ����� ���� 0���� �ٲٰ� f - 1(f�� �� �� ���� ��ġ)�� ����� ���� 1�� �ٲ۴�.
�׷��� �� ������ �ű�� �Ͱ� ���� ���°� �ȴ�.
�̸� ���ؼ� �� ���� p���� �����صΰ� �־�� �ϰ�, �ʱ� ���¿��� f�� m �̻��� �Ǿ�� �Ѵ�.
����, �ʱ�ȭ�� �����Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��

��ó : NWERC 2011 C��
*/

int seg[SZ * 2], pos[103000];

int getupper(int s, int e, int p, int ss, int se) {
    if (s > se || e < ss) return 0;
    if (s <= ss && se <= e) return seg[p];
    return getupper(s, e, p << 1, ss, (ss + se) >> 1) + getupper(s, e, (p << 1) + 1, ((ss + se) >> 1) + 1, se);
}

void upd(int p, int x) {
    seg[SZ + p] = x;
    for (int i = (SZ + p) >> 1; i >= 1; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int t, n, m, x;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2011\\testdata\\C.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2011\\testdata\\C_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < SZ; i++) {
            if (m <= i && i < n + m) seg[SZ + i] = 1;
            else seg[SZ + i] = 0;
        }
        for (int i = SZ - 1; i >= 1; i--) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
        for (int i = 1; i <= n; i++) pos[i] = m + i - 1;

        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            printf("%d ", getupper(0, pos[x] - 1, 1, 0, SZ - 1));
            upd(pos[x], 0);
            upd(m - i, 1);
            pos[x] = m - i;
        }
        printf("\n");
    }
    return 0;
}