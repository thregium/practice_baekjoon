#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100)���� ������ ���� �׷������� M���� ����� ���� ������ ���� ����ġ�� �־��� ��,
K(K <= 100)���� ���������� �Ÿ� ���� ���� ���� ���� ��� ��ȣ�� ���� ���� ������ ã�´�.

�ذ� ��� : �÷��̵�-���� �˰����� �̿��Ͽ� �� ���� �� ������ �Ÿ��� ���ϰ�, �� ������ Ȯ���ϸ鼭
�Ÿ� ���� ���� ���� ���� ���� ������ ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����

��ó : ���δ� 2016 L��
*/

int dist[128][128], room[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int t, n, m, k, a, b, c, best = 0, bn = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dist[i][j] = INF;
            dist[i][i] = 0;
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
        best = INF, bn = -1;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &room[i]);
        }
        for (int i = 1; i <= n; i++) {
            a = 0;
            for (int j = 0; j < k; j++) {
                a += dist[i][room[j]];
            }
            if (a < best) {
                best = a;
                bn = i;
            }
        }
        if (bn < 0) return 1;
        printf("%d\n", bn);
    }
    return 0;
}