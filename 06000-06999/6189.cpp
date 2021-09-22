#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : R * C(R, C <= 100) ũ���� ���ڿ��� '*'�� �ִ� ������ ������ �ʰ� �����¿�� �������� 'C'���� 'B'�� ����
�ִܰŸ��� ���Ѵ�.

�ذ� ��� : BFS�� �̿��� �ִܰŸ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2008O B4��
*/

char map[128][128];
int vis[128][128], dist[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y] || map[x][y] == '*') return 0;
    return 1;
}

void bfs(int x, int y, int d) {
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
    int bx = -1, by = -1, cx = -1, cy = -1;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'B') {
                if (bx >= 0) return 1;
                bx = i;
                by = j;
            }
            else if (map[i][j] == 'C') {
                if (cx >= 0) return 2;
                cx = i;
                cy = j;
            }
        }
    }
    if (bx < 0 || cx < 0) return 3;
    bfs(cx, cy, 0);
    if (!vis[bx][by]) return 4;
    printf("%d", dist[bx][by]);
    return 0;
}