#include <stdio.h>
#include <tuple>
#include <queue>
using namespace std;

/*
���� : N * M(N, M <= 100) ũ���� ���忡 �κ��� �ִ�. �κ��� ��� �ѹ��� ������ 1 ~ 3ĭ �����̰ų� ���� �Ǵ� ���������� 90�� ȸ���� �� �ִ�.
�̶�, �κ��� ���� ��ġ, ���⿡�� ���� ��ġ, �������� �ű�µ� �ʿ��� �ּ����� ��� Ƚ���� ���Ѵ�.

�ذ� ��� : BFS�� ���� ���� ���¿��� ��ǥ ���±����� �ִܰŸ��� ���ϸ� �ȴ�. ���� �κ��� ��ġ�� ������ �������� ������ �ȴ�.
�߰��� �����ִٸ� �������� �� �� �ִ��� ���� ���� �Ұ����Կ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����

��ó : ���� 2005�� ��3��
*/

int factory[128][128], vis[128][128][5], dist[128][128][5];
int dxy[5][2] = { {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int right[5] = { 0, 3, 4, 2, 1 }, left[5] = { 0, 4, 3, 1, 2 };
int m, n;
queue<tuple<int, int, int>> q;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (factory[x][y]) return -1;
    if (vis[x][y][d]) return 0;
    return 1;
}

void bfs(int x, int y, int d) {
    q.push(make_tuple(x, y, d));
    vis[x][y][d] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());
        q.pop();
        if (!vis[x][y][left[d]]) {
            q.push(make_tuple(x, y, left[d]));
            vis[x][y][left[d]] = 1;
            dist[x][y][left[d]] = dist[x][y][d] + 1;
        }
        if (!vis[x][y][right[d]]) {
            q.push(make_tuple(x, y, right[d]));
            vis[x][y][right[d]] = 1;
            dist[x][y][right[d]] = dist[x][y][d] + 1;
        }
        for (int i = 1; i <= 3; i++) {
            if (isvalid(x + dxy[d][0] * i, y + dxy[d][1] * i, d) == -1) break;
            if (isvalid(x + dxy[d][0] * i, y + dxy[d][1] * i, d) == 0) continue;
            q.push(make_tuple(x + dxy[d][0] * i, y + dxy[d][1] * i, d));
            vis[x + dxy[d][0] * i][y + dxy[d][1] * i][d] = 1;
            dist[x + dxy[d][0] * i][y + dxy[d][1] * i][d] = dist[x][y][d] + 1;
        }
    }
}

int main(void) {
    int x, y, d;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &factory[i][j]);
        }
    }
    scanf("%d %d %d", &x, &y, &d);
    bfs(x - 1, y - 1, d);
    scanf("%d %d %d", &x, &y, &d);
    printf("%d", dist[x - 1][y - 1][d]);
    return 0;
}