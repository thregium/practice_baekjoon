#include <stdio.h>

/*
���� : M(M <= 2000)���� ���� N(N <= 2000)���� ������ ������, �� ���� OR�� ���� AND �Ͽ��� ��
���� ���� ��찡 �ִ� �� Ȯ���ϰ� �ִٸ� �׷��� ����� ����Ѵ�. ��ü ���� ���� 3000 ���ϴ�.
����, �� ������ 1�� ���� �ִ� 1���̴�.

�ذ� ��� : �켱 ��� ������ 0���� ���� ����, ��� ���� �����ϰų�, 1�� ���� ���� �������� �ʴ�
��찡 ���� �� ���� �ݺ��Ѵ�. 1�� �ִ� ���� �������� �ʴ´ٸ� �� ������ ���� 1�� �ٲٰ� �ݺ��Ѵ�.
1�� ���� ���� �������� �ʴ� ��� ������ ���̹Ƿ� ���� ��찡 ����,
�����ϴ� ��쿡�� �׶��� �� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �ùķ��̼�

��ó : GCJ 2008A B2��
*/

int cust[2048][6144], custt[2048], res[2048];

int main(void) {
    int t, n, m, ok, good, malt, poss;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &custt[i]);
            for (int j = 0; j < custt[i] * 2; j += 2) {
                scanf("%d %d", &cust[i][j], &cust[i][j + 1]);
            }
        }
        for (int i = 1; i <= n; i++) {
            res[i] = 0;
        }
        poss = 1;
        while (1) {
            good = 1;
            for (int i = 0; i < m; i++) {
                ok = 0, malt = 0;
                for (int j = 0; j < custt[i] * 2; j += 2) {
                    if (res[cust[i][j]] == cust[i][j + 1]) {
                        ok = 1;
                    }
                    if (cust[i][j + 1]) malt = 1;
                }
                if (!ok) {
                    if (malt) {
                        for (int j = 0; j < custt[i] * 2; j += 2) {
                            if (res[cust[i][j]] < cust[i][j + 1]) {
                                res[cust[i][j]] = 1;
                            }
                        }
                    }
                    else poss = 0;
                    good = 0;
                }
                if (!good) break;
            }
            if (good || !poss) break;
        }

        if (poss == 0) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
        }
        else {
            printf("Case #%d: ", tt);
            for (int i = 1; i <= n; i++) {
                printf("%d%c", res[i], i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}