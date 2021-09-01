#include <stdio.h>

/*
���� : N(N <= 500)���� ������ �־����� ������ �ٲ� M(M <= 25000)���� ���� �־�����. �̶�, �ٲ� ������ ���� �� �ִ���
Ȯ���ϰ�, �����ϴٸ� �ٲ� ������ ���Ѵ�.

�ذ� ��� : ��� ������ �ٸ� �ֿ� ���� ������ ���� �ʿ��� ���� ������ ������ �ߴ´�. ������ ���� ������ ���� �ֵ鳢�� ����
�ٲٴ� ���� ����� ������ ���� ����� �̿��Ѵ�. ������ �ٲ� ���� ������ ������ �ٲٸ� �ȴ�.
���� ���� ������ ���� ���� ����� �ٲ� �����̴�. �߰��� ����Ŭ�� ���� ��쿡�� ������ ���� �� ���� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����

��ó : NWERC 2010 E��
*/

int comp[512][512], orank[512], nrank[512], ins[512];

int main(void) {
    int t, n, m, a, b, sel, r;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2010\\testdata\\E.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2010\\testdata\\E_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &orank[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                comp[orank[i]][orank[j]] = 1;
                ins[orank[j]]++;
            }
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (comp[a][b]) {
                comp[a][b] = 0;
                comp[b][a] = 1;
                ins[a]++, ins[b]--;
            }
            else {
                comp[a][b] = 1;
                comp[b][a] = 0;
                ins[a]--, ins[b]++;
            }
        }

        r = 1;
        for (int i = 1; i <= n; i++) {
            sel = 0;
            for (int j = 1; j <= n; j++) {
                if (ins[j] == 0) {
                    sel = j;
                    break;
                }
            }
            if (!sel) {
                printf("IMPOSSIBLE\n");
                r = 0;
                break;
            }
            ins[sel]--;
            nrank[i] = sel;
            for (int j = 1; j <= n; j++) ins[j] -= comp[sel][j];
        }
        if (r) {
            for (int i = 1; i <= n; i++) printf("%d ", nrank[i]);
            printf("\n");
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) comp[i][j] = 0;
            ins[i] = 0;
        }
    }
    return 0;
}
