#include <stdio.h>
#include <tuple>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N * M(N, M <= 1000) ũ���� 0�� 1�� �̷���� �迭�� �ִ�. Ȧ�� ��° �̵����� 1�� ĭ����
�̵� �����ϰ�, 1�� ĭ���δ� �ִ� K(K <= 10)ȸ�� �� �� �ִٸ�, (1, 1)���� (N, M)���� �̵��ϱ� ����
�̵��� �ּ� �� ȸ �ؾ� �ϴ� �� ���Ѵ�. �̵� �Ұ����ϴٸ� -1�� ����Ѵ�.
�̵��� �����¿�� ���ڸ� ������ �ִ�. ���� ���¿����� �̵� Ƚ���� �þ��.

�ذ� ��� : �� ��ġ�� 1�� ĭ�� �� Ƚ��, 1�� ĭ�� �̵� ������ �� ���θ� �������� �ΰ�
BFS�� �����Ѵ�. ���°� ������ ���̹Ƿ� �̵��� �Ǽ����� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

char wall[1024][1024], vis[1024][1024][16][2];
int dist[1024][1024][16][2];
int n, m, k;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<tuple<int, int, int, int>> q;

int isvalid(int x, int y, int z, int dn) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y][z][dn]) return 0;
    if (wall[x][y] == '1') {
        if ((z == k || !dn)) return 0;
        else return 2;
    }
    return 1;
}

int bfs(int x, int y, int z, int dn) {
    int t, r = INF;
    q.push(make_tuple(x, y, z, dn));
    vis[x][y][z][dn] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        dn = get<3>(q.front());
        q.pop();
        if (!vis[x][y][z][!dn]) {
            dist[x][y][z][!dn] = dist[x][y][z][dn] + 1;
            vis[x][y][z][!dn] = 1;
            q.push(make_tuple(x, y, z, !dn));
        }
        for (int i = 0; i < 4; i++) {
            t = isvalid(x + dxy[i][0], y + dxy[i][1], z, !dn);
            if (t) {
                dist[x + dxy[i][0]][y + dxy[i][1]][z + t - 1][!dn] = dist[x][y][z][dn] + 1;
                vis[x + dxy[i][0]][y + dxy[i][1]][z + t - 1][!dn] = 1;
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z + t - 1, !dn));
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 2; j++) {
            if (!vis[n - 1][m - 1][i][j]) continue;
            if (dist[n - 1][m - 1][i][j] < r) r = dist[n - 1][m - 1][i][j];
        }
    }
    if (r == INF) return -2;
    else return r;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", wall[i]);
    }
    printf("%d", bfs(0, 0, 0, 0) + 1);
    return 0;
}