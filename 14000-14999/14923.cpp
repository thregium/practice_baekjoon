#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : N * (N, M <= 1000) ũ���� 0�� 1�� �̷���� �迭���� (Hx, Hy)���� ����Ͽ� (Ex, Ey)�� �̵��ϸ�
1�� ���� �ִ� 1ȸ�� ������ �� ���� ���� �ּ� �̵� Ƚ��(�����¿�)�� ���Ѵ�. �Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : BFS�� �ϵ�, ���� �μ������� ���θ� ������ �߰��� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ȫ�ʹ� 2017 F��
*/

int mp[1024][1024], vis[1024][1024][2], dist[1024][1024][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
deque<tuple<int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (vis[x][y][z]) return 0;
    if (mp[x][y] == 1) return -1;
    return 1;
}

void bfs(int x, int y) {
    int d, z, t;
    vis[x][y][0] = 1;
    q.push_back(make_tuple(x, y, 0));
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop_front();
        d = dist[x][y][z];
        for (int i = 0; i < 4; i++) {
            t = isvalid(x + dxy[i][0], y + dxy[i][1], z);
            if (!t) continue;
            if (t > 0) {
                q.push_back(make_tuple(x + dxy[i][0], y + dxy[i][1], z));
                vis[x + dxy[i][0]][y + dxy[i][1]][z] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z] = dist[x][y][z] + 1;
            }
            if (t < 0) {
                if (z > 0 || vis[x + dxy[i][0]][y + dxy[i][1]][z + 1]) continue;
                q.push_back(make_tuple(x + dxy[i][0], y + dxy[i][1], z + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][z + 1] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z + 1] = dist[x][y][z] + 1;
            }
        }
    }
}

int main(void) {
    int hx, hy, ex, ey, r = -1;
    scanf("%d %d%d %d%d %d", &n, &m, &hx, &hy, &ex, &ey);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    bfs(hx, hy);
    if (vis[ex][ey][0]) r = dist[ex][ey][0];
    if (vis[ex][ey][1]) {
        if (r < 0 || r > dist[ex][ey][1]) r = dist[ex][ey][1];
    }
    printf("%d", r);
    return 0;
}