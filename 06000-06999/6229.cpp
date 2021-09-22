#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : M * N(M, N <= 30) ũ���� ���ڿ��� �� ���� �̵��� ���� �������� M1, �ٸ� �� �������� M2ĭ ��ŭ �����̴� ���� �����ϴ�.
��, �̵��� ���� �ٱ����� �����ų� 0�̳� 2�� ���� ĭ���δ� �̵� �Ұ����ϴ�. �̶�, 3�� ���� ĭ���� 4�� ���� ĭ����
�̵��ϴµ� �ּ� �� ȸ �̵��� �ʿ����� ���Ѵ�. �ݵ�� �̵��� ������ ��츸 �־�����.

�ذ� ��� : ���� �� �̵� ������ ������ ������ ����, BFS�� ���� 3�� ���� ĭ���� �����ϴ� �ִܰŸ��� ���� ���� ����,
4�� ���� �������� �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2007F B2��
*/

int lily[32][32], vis[32][32], dist[32][32], dxy[8][2];
int m, n;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (vis[x][y] || lily[x][y] != 1) return 0;
    return 1;
}

int bfs(int x, int y, int d, int xf, int yf) {
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        if (x == xf && y == yf) return d;
        for (int i = 0; i < 8; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
    return -1;
}

int main(void) {
    int m1, m2, xs = -1, ys = -1, xf = -1, yf = -1, r;
    scanf("%d %d %d %d", &m, &n, &m1, &m2);
    for (int i = 0; i < 8; i++) {
        if (i & 4) {
            if (i & 1) dxy[i][0] = m1;
            else dxy[i][0] = -m1;
            if (i & 2) dxy[i][1] = m2;
            else dxy[i][1] = -m2;
        }
        else {
            if (i & 1) dxy[i][0] = m2;
            else dxy[i][0] = -m2;
            if (i & 2) dxy[i][1] = m1;
            else dxy[i][1] = -m1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &lily[i][j]);
            if (lily[i][j] == 3) {
                lily[i][j] = 1;
                xs = i;
                ys = j;
            }
            else if (lily[i][j] == 4) {
                lily[i][j] = 1;
                xf = i;
                yf = j;
            }
        }
    }
    if (xs < 0 || xf < 0) return 1;

    r = bfs(xs, ys, 0, xf, yf);
    if (r < 0) return 2;
    printf("%d", r);
    return 0;
}