#include <stdio.h>
#define INF 103000

/*
���� : N(N <= 300)���� ���� �ְ�, �� ������ M(M <= 5000)���� �뼱���� ����Ǿ� �ִ�.
S�� ������ ����Ͽ� L(L <= 16)���� �Ĵ� �� �ִ��� ���� �Ĵ翡�� ������ �԰� T(T <= 100000) �ð� ����
S�� ������ ���ƿ��� �Ѵ�. �� �Ĵ��� ��ġ�� �Դµ� �ɸ��� �ð��� �־��� ��,
������ ���� �� �ִ� �ִ��� �Ĵ� ���� ���Ѵ�. S�� ���� ��ó���� �Ĵ��� ����, ������ �Ĵ���� ���� ������
�ð��� �ҿ���� �ʴ´�.

�ذ� ��� : �÷��̵�-���� �˰����� �̿��� �Ÿ��� ��ó���� ����, ��ƮDP�� �̿��Ͽ� �湮��
�Ĵ��� ���պ��� ���ƿ��� �ִ� �Ÿ��� ���ϰ�, �� �Ÿ��� T ������ �� ��� �湮�� �Ĵ���
������ ���� ���� ���� �Ĵ� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, DP, ��ƮDP, �÷��̵�-����

��ó : JAG 2013P C��
*/

int dist[384][384], siro[17][2], mem[65536][17];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, l, s, t, a, b, c, res, popcnt;
    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            dist[a][b] = c;
            dist[b][a] = c;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i = 0; i < l; i++) {
            scanf("%d %d", &siro[i][0], &siro[i][1]);
        }
        for (int i = 0; i < (1 << l); i++) {
            for (int j = 0; j <= l; j++) mem[i][j] = INF;
        }
        mem[0][l] = 0;
        siro[l][0] = s;
        siro[l][1] = 0;
        for (int i = 0; i < (1 << l); i++) {
            for (int j = 0; j <= l; j++) {
                if ((i >> j) & 1) {
                    for (int k = 0; k <= l; k++) {
                        if (k == l || ((i >> k) & 1)) {
                            mem[i][j] = small(mem[i][j], mem[i ^ (1 << j)][k] +
                                siro[j][1] + dist[siro[k][0]][siro[j][0]]);
                        }
                    }
                }
                else if (j == l) {
                    for (int k = 0; k < l; k++) {
                        if ((i >> k) & 1) {
                            mem[i][j] = small(mem[i][j], mem[i][k] + dist[siro[k][0]][siro[j][0]]);
                        }
                    }
                }
            }
        }

        res = 0;
        for (int i = 0; i < (1 << l); i++) {
            if (mem[i][l] > t) continue;
            popcnt = 0;
            for (int j = 0; j < l; j++) {
                if ((i >> j) & 1) popcnt++;
            }
            if (popcnt > res) res = popcnt;
        }
        printf("%d\n", res);
    }
    return 0;
}