#include <stdio.h>

/*
���� : N(N <= 1000)���� ���� M(M <= 1000)���� ��⿡ ���� �� ���� ������ �־�����. �̶�, �� ���� ��Ÿ������ �·� ���
���� ���� �Ͱ� ���� ���� �Ϳ� ���� 1000�� ���� ���� �κ��� ���Ѵ�. ��, 0���� 0������ ��Ÿ������ �·� 0���� �����Ѵ�.

�ذ� ��� : ��� ����� ����� Ȯ���ϸ� �� ���� ������ ������ �迭�� �����Ѵ�.
��� ����� Ȯ���� ������ �� �� �� ������ ������ ���� ��Ÿ������ �·��� ���������� ����Ѵ�. 0���� 0������ ��쿡 ����
����ó���� ����� �ϰ�, �Ǽ� ������ �����ϱ� ���� �ſ� ���� ���� �����ִ� ���� ���� �ʴ´�.
������ ����� ����, ���� ū �Ͱ� ���� ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰����� : ����, ����

��ó : Daejeon 2015I J��
*/

int s[1024], sa[1024];

int pyt(double s, double a) {
    if (s == 0 && a == 0) return 0;
    double r = (s * s) / (s * s + a * a);
    r = r * 1000 + 0.0000001;
    return (int)r;
}

int main(void) {
    int t, n, m, a, b, p, q, rh, rl;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            s[i] = 0;
            sa[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &a, &b, &p, &q);
            s[a] += p;
            s[b] += q;
            sa[a] += q;
            sa[b] += p;
        }
        rh = -1, rl = 1001;
        for (int i = 1; i <= n; i++) {
            if (pyt(s[i], sa[i]) > rh) rh = pyt(s[i], sa[i]);
            if (pyt(s[i], sa[i]) < rl) rl = pyt(s[i], sa[i]);
        }
        if (rh < 0 || rl > 1000) return 1;
        printf("%d\n%d\n", rh, rl);
    }
    return 0;
}