#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : N * N(N <= 200) ũ���� ���ڿ� K(K <= 1000)������ ���̷����� �ִ�. �� ���̷������� �� �ʸ��� �ֺ� �������� ����������.
��, �̹� �ٸ� ���̷����� �ִ� ĭ���δ� ������ �ʴ´�. �� �ʸ��� ������ ������ ���̷����� ��ȣ �����̴�.
�̶�, S(S <= 10000)�� �� (X, Y)�� �ִ� ���̷����� ������ ���Ѵ�. ���ٸ� 0�� ����Ѵ�.

�ذ� ��� : �� ���̷������� ��ȣ ������ ť�� ���� ����, BFS�� �Ѵ�. (X, Y)�� �ִ� ���̷����� ���ų�
���� �ð��� S���� ũ�ٸ� ���̷����� ���� ���̹Ƿ� 0�� ����ϰ�, �� �ܿ��� �� ĭ�� ���̷����� ����ϸ� �ȴ�.
���� ������ ���̷����� ���� ĭ�� ���� �� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

int vis[256][256], dist[256][256];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
queue<tuple<int, int, int>> q;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    int v, d;
    while (q.size()) {
        v = get<0>(q.front());
        x = get<1>(q.front());
        y = get<2>(q.front());
        q.pop();
        d = dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(make_tuple(v, x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = v;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int k, s, x, y;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &vis[i][j]);
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (vis[j][k] == i) q.push(make_tuple(i, j, k));
            }
        }
    }
    bfs(0, 0);
    scanf("%d %d %d", &s, &x, &y);
    if (!vis[x][y] || dist[x][y] > s) printf("0");
    else printf("%d", vis[x][y]);
    return 0;
}