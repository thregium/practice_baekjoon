#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 1000)���� �������� �̷���� Ʈ���� �� ������ ����ġ�� �־��� ��, M(M <= 1000)���� ���� �� ���� �Ÿ��� ����Ѵ�.

�ذ� ��� : �÷��̵�-���� �˰����� �̿��� ��� ���� ���� �Ÿ��� ���ϰ� �� ���� ���� �Է¹��� �� ���� �Ÿ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����
*/

int dist[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 1; i < n; i++) {
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
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
    return 0;
}