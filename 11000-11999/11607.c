#include <stdio.h>

/*
���� : N * M(N, M <= 500) ũ���� �����ǿ� ������ �����ִ�. �� ĭ������ �ش� ����ŭ �����¿�� ������ ĭ����
�̵��� �����ϴٰ� �� ��, ���� ������ ������ �Ʒ��� �̵��ϴµ� �ʿ��� �ּ� �̵� Ƚ���� ���Ѵ�.

�ذ� ��� : �� ĭ���� �̵� ������ ĭ���� �̸� ������ ����, ���� �� ĭ�������� BFS�� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : PacNW 2015 O�� // SEUSA 2015 E�� / 2015D2 E��
*/

char grid[512][512];
int vis[512][512], dist[512][512], adj[512][512][4], q[262144];
int n, m, qf = 0, qr = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    q[qr++] = x * 512 + y;
    vis[x][y] = 1;
    while (qf < qr) {
        x = (q[qf] >> 9);
        y = (q[qf] & 511);
        qf++;
        for (int i = 0; i < 4; i++) {
            if (isvalid(adj[x][y][i] >> 9, adj[x][y][i] & 511)) {
                q[qr++] = adj[x][y][i];
                vis[adj[x][y][i] >> 9][adj[x][y][i] & 511] = 1;
                dist[adj[x][y][i] >> 9][adj[x][y][i] & 511] = dist[x][y] + 1;
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) adj[i][j][k] = -1;
            if (i - (grid[i][j] - '0') >= 0) adj[i][j][0] = (i - (grid[i][j] - '0')) * 512 + j;
            if (j + (grid[i][j] - '0') < m) adj[i][j][1] = i * 512 + (j + (grid[i][j] - '0'));
            if (i + (grid[i][j] - '0') < n) adj[i][j][2] = (i + (grid[i][j] - '0')) * 512 + j;
            if (j - (grid[i][j] - '0') >= 0) adj[i][j][3] = i * 512 + (j - (grid[i][j] - '0'));
        }
    }
    bfs(0, 0);
    if (!vis[n - 1][m - 1]) printf("IMPOSSIBLE");
    else printf("%d", dist[n - 1][m - 1]);
    return 0;
}