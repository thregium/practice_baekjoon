#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100)���� �������� �̷���� ���� �׷������� ��� �������� �Ÿ� ���� ���� ª�� �� ������ ã�Ƽ�
�� �� �������� ��� ���������� �Ÿ� �� * 2�� �� �� ������ ����Ѵ�. ���� ������ ��� ���������� ���� ���� ����Ѵ�.

�ذ� ��� : �÷��̵�-���� �˰����� �̿��Ͽ� ��� ���� �� ������ �Ÿ��� ���� ��,
�� �������� Ȯ���ϸ� �� ������ �ٸ� ������ ���� �Ÿ��� ���� ª�� ���� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����, ���Ʈ ����

��ó : ��ȣ���� 2ȸ 4��
*/

int dist[128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, a, b, r, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    a = -1, b = -1, r = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            t = 0;
            for (int k = 1; k <= n; k++) {
                t += small(dist[i][k], dist[j][k]);
            }
            if (t < r) {
                r = t;
                a = i;
                b = j;
            }
        }
    }
    if (a < 0) return 1;
    printf("%d %d %d", a, b, r * 2);
    return 0;
}