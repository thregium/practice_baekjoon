#include <stdio.h>

/*
���� : N(N <= 100)���� �������� �̷���� ���� �׷����� ���� ����� �־��� ��, M�� �������� ����Ѵٸ�
�ش� ���������� �ִܰŸ��� ������ ���� ������������ ����Ѵ�.

�ذ� ��� : M�� �������� �����ϴ� BFS�� ���� ����, ���� ��ȣ�� ������������ Ȯ���ϸ� �湮�� �����鿡 ����
�ִܰŸ����� ����� �迭�� �����Ѵ�. �� ����, �̸� ���ʷ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2011M B2��
*/

int q[1024], vis[128], dist[128], adj[128][128], res[128][128];
int qf = 0, qr = 0;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    q[qr++] = m;
    vis[m] = 1;
    while (qr > qf) {
        m = q[qf++];
        for (int i = 1; i <= n; i++) {
            if (adj[m][i] && !vis[i]) {
                q[qr++] = i;
                vis[i] = 1;
                dist[i] = dist[m] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) continue;
        res[dist[i]][++res[dist[i]][0]] = i; //res[i][0] = res[i]�� ũ��
    }

    for (int i = 0; res[i][0]; i++) {
        for (int j = 1; j <= res[i][0]; j++) {
            printf("%d", res[i][j]);
            if (j < res[i][0]) printf(" ");
        }
        if (res[i + 1][0]) printf("\n");
    }
    return 0;
}