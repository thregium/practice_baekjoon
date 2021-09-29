#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : X * Y(X, Y <= 150) ũ���� ü���ǿ��� '*'�� �ִ� ĭ�� ������ �ʰ� 'K'���� ����Ʈ�� ������ 'H'�� �����̴�
�ִ� �̵� Ƚ���� ���Ѵ�.

�ذ� ��� : K���� �����ϴ� BFS�� ���� ����, H������ �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2009N B2��
*/

char map[192][192];
int vis[192][192], dist[192][192];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
queue<pair<int, int>> q;
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
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
        for (int i = 0; i < 8; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int kx = -1, ky = -1, hx = -1, hy = -1;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'K') {
                kx = i;
                ky = j;
            }
            else if (map[i][j] == 'H') {
                hx = i;
                hy = j;
            }
        }
    }
    if (kx < 0 || hx < 0) return 1;
    bfs(kx, ky, 0);
    if (!vis[hx][hy]) return 2;
    printf("%d", dist[hx][hy]);
    return 0;
}