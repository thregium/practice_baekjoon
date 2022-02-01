#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : N * M(N, M <= 1000) ũ���� �������� �����¿�� �̵��ϸ� 1�� �ִ� ĭ(��)�� K(K <= 10)ȸ ���Ϸ� ������
�� ���� ������ ������ �Ʒ��� �̵��� �� �ִ��� ���ϰ�, �ִٸ� �� ���� �ִܰŸ��� ���Ѵ�.

�ذ� ��� : �湮 �迭�� ���� �μ� Ƚ���� ���� ������ �� BFS�� �Ѵ�. 1�� ĭ�� ������ ���� �μ� Ƚ���� 1�� �ø���,
K���� Ŀ���� �� �� ���� ������ ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

char map[1024][1024], vis[1024][1024][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, k;
queue<tuple<int, int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x <= 0 || y <= 0 || x > n || y > m) return 0;
    if (vis[x][y][z] || z > k) return 0;
    return map[x][y] - '0' + 1;
}

int bfs(int x, int y) {
    int b = 0, d = 1;
    q.push(make_tuple(x, y, b, d));
    vis[x][y][b] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        b = get<2>(q.front());
        d = get<3>(q.front());
        q.pop();
        if (x == n && y == m) return d;
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], b) == 1) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], b, d + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][b] = 1;
            }
            else if (isvalid(x + dxy[i][0], y + dxy[i][1], b + 1) == 2) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], b + 1, d + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][b + 1] = 1;
            }
        }
    }
    return -1;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }
    printf("%d", bfs(1, 1));
    return 0;
}