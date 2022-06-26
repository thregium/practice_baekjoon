#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * M(N, M <= 500) ũ���� �迭�� ���� ��ֹ��� �ִ� K���� ĭ�� ����
H * W(H, W <= 10) ũ���� ���簢���� ���������� �������� �ű�� ���� �ʿ��� �ּ� �̵� Ƚ���� ���Ѵ�.
�Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : ���� �� �迭�� ���� ����, ���簢���� ��ġ�� ���� BFS�� �Ѵ�. Ž�� �ð��� �����ϱ� ����
���� ���� ����ϸ� ����(�ʼ��� �ƴϴ�).

�ֿ� �˰��� : �׷��� �̷�, BFS, ���� ��
*/

int grid[1024][1024], vis[1024][1024], dist[1024][1024];
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x <= 0 || y <= 0 || x + h - 1 > n || y + w - 1 > m) return 0;
    if (vis[x][y] || (grid[x + h - 1][y + w - 1] - grid[x - 1][y + w - 1] - grid[x + h - 1][y - 1] + grid[x - 1][y - 1])) return 0;
    return 1;
}

void bfs(int x, int y) {
    int d;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int k, x, y, sr, sc, fr, fc;
    scanf("%d %d %d %d %d", &n, &m, &h, &w, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        grid[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) grid[i][j] += grid[i][j - 1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) grid[j][i] += grid[j - 1][i];
    }
    scanf("%d %d %d %d", &sr, &sc, &fr, &fc);
    bfs(sr, sc);
    if (!vis[fr][fc]) printf("-1");
    else printf("%d", dist[fr][fc]);
    return 0;
}