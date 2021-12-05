#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : H * W(H, W <= 100) ũ���� ü���ǿ��� (1, 1)���� (i, j)���� ���µ� ��� ����Ʈ�� �̵� Ƚ���� ���Ѵ�.
���ٸ� "NEVAR"�� ����Ѵ�.

�ذ� ��� : BFS�� ���� �� ĭ���� �̵��� �ִܰŸ��� ���Ѵ�. (i, j)�� �湮�� ���� ���ٸ� NEVAR�� ����ϰ�,
�ִٸ� �ִܰŸ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : LvOI 10II 2��
*/

int vis[128][128], dist[128][128];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > h || y > w) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    int d;
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
    int i, j;
    scanf("%d %d %d %d", &h, &w, &i, &j);
    bfs(1, 1);
    if (vis[i][j]) printf("%d", dist[i][j]);
    else printf("NEVAR");
    return 0;
}