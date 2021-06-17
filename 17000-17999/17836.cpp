#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * M(N, M <= 100) ũ���� ���ڿ��� (1, 1)���� (N, M)���� ���� ��ġ�� �ʰ� ���ų�
2�� �ִ� ĭ���� ���� ��ġ�� �ʰ� �� ���� (N, M)���� ���� ��ġ������ ��� ���� �� �� �ִ�. �� �� �� ���� ���� �̵� �Ÿ��� ���Ѵ�.

�ذ� ��� : BFS�� ���� 2�� �ִ� ĭ�� (N, M)������ �Ÿ��� ���� ���ϰ� 2�� �ִ� ĭ���� (N, M)���� ����ư �Ÿ��� ���� ����
(N, M)������ �Ÿ��� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ȫ�ʹ� 2019 B��
*/

int castle[128][128], vis[128][128], dist[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, t;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (castle[x][y] == 1 || vis[x][y]) return 0;
    return 1;
}

int bfs(int x, int y) {
    int gdist = t + 1, pdist = t + 1;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (castle[x][y] == 2) gdist = dist[x][y] + n - x + m - y;
        if (x == n && y == m) pdist = dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
        }
    }
    if (gdist < pdist) return gdist;
    else return pdist;
}

int main(void) {
    int r;
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &castle[i][j]);
            if (i == 1 && j == 1 && castle[i][j] == 1) return 1;
            if (i == n && j == m && castle[i][j] == 1) return 2;
        }
    }
    r = bfs(1, 1);
    if (r > t) printf("Fail");
    else printf("%d", r);
    return 0;
}