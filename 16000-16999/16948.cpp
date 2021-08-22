#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * N(N <= 200) ũ�� ���忡�� Ư���� 6�� �������� ������ �� �ִ�(���� ����) ���� �ִ�.
�� ���� ���忡�� ������ �ʰ� (R1, C1)���� (R2, C2)�� ������ �� �ִ��� Ȯ���ϰ� �����ϴٸ� �ּ� �̵� Ƚ���� ���Ѵ�.

�ذ� ��� : BFS�� ���� R1, C1���� ������ ��� ���������� �ִܰŸ��� ���Ѵ�. (R2, C2)�� �湮�� ���� ���ٸ� �� �� ���� ���̰�,
�湮�� ���� �ִٸ� �ִܰŸ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

int vis[256][256], dist[256][256];
int dxy[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
}

int main(void) {
    int n, r1, c1, r2, c2;
    scanf("%d", &n);
    h = n, w = n;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    bfs(r1, c1);
    if (vis[r2][c2]) printf("%d", dist[r2][c2]);
    else printf("-1");
    return 0;
}