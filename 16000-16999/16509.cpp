#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : ����ǿ� ��� ���� ��ġ�� �־�����. �̶�, ���� ���� ��� ���� �ּ� �� ȸ �������� �ϴ� �� ���Ѵ�.

�ذ� ��� : ���� ��ġ���� BFS�� �ϸ� �ȴ�. ��, ���� ���� ��� ���� �ִ� ��쿡 �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����

��ó : �泲�� 2ȸ G��
*/

int vis[16][16], dist[16][16];
int dxy[8][2] = { {3, 2}, {2, 3}, {2, -3}, {3, -2}, {-3, -2}, {-2, -3}, {-2, 3}, {-3, 2} };
int dmv[8][2][2] = { {{1, 0}, {2, 1}}, {{0, 1}, {1, 2}}, {{0, -1}, {1, -2}}, {{1, 0}, {2, -1}},
{{-1, 0}, {-2, -1}}, {{0, -1}, {-1, -2}}, {{0, 1}, {-1, 2}}, {{-1, 0}, {-2, 1}} };
int r, c;
queue<pair<int, int>> q;

int isvalid(int x1, int y1, int d) {
    int x2 = x1 + dxy[d][0];
    int y2 = y1 + dxy[d][1];
    if (x2 < 0 || y2 < 0 || x2 > 9 || y2 > 8) return 0;
    if (vis[x2][y2] || (x1 + dmv[d][0][0] == r && y1 + dmv[d][0][1] == c) ||
        (x1 + dmv[d][1][0] == r && y1 + dmv[d][1][1] == c)) return 0;
    if (x2 == r && y2 == c) return -1;
    return 1;
}

int bfs(int x, int y) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        if (x == r && y == c) return dist[x][y];
        q.pop();
        for (int i = 0; i < 8; i++) {
            if (isvalid(x, y, i)) {
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    return -1;
}

int main(void) {
    int x, y;
    scanf("%d %d%d %d", &x, &y, &r, &c);
    printf("%d", bfs(x, y));
    return 0;
}