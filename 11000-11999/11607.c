#include <stdio.h>

/*
문제 : N * M(N, M <= 500) 크기의 격자판에 수들이 쓰여있다. 각 칸에서는 해당 수만큼 상하좌우로 떨어진 칸으로
이동이 가능하다고 할 때, 왼쪽 위에서 오른쪽 아래로 이동하는데 필요한 최소 이동 횟수를 구한다.

해결 방법 : 각 칸에서 이동 가능한 칸들을 미리 저장한 다음, 왼쪽 위 칸에서부터 BFS를 하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : PacNW 2015 O번 // SEUSA 2015 E번 / 2015D2 E번
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