#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * M(N, M <= 1000) ũ���� ���� �� �ִ� ���� ���� ���� ǥ�õ� ������ �־��� ��, ���� �������� ��� �������� �̵��Ÿ��� ���� ���Ѵ�.

�ذ� ��� :  BFS�� ���� ��� ���� �̵��Ÿ��� ���ϸ� �ȴ�. �Ÿ� �迭�� ����ϸ� �� ����.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ������ 2017M F��
*/

int map[1024][1024], vis[1024][1024], dist[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || !map[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int x = 0, y = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    bfs(x, y);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) printf("%d ", dist[i][j]);
            else if (map[i][j]) printf("-1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}