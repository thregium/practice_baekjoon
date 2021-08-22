#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : H * W(H, W <= 30) ũ���� ���ڿ��� ���� ������ ���� �����ִ��� ���ΰ� ��� ���� ���� �־�����.
�̶�, ���� �� ���ڿ��� ������ �Ʒ� ���ڷ� ���� ����� �ִٸ� �ִܰŸ��� ����ϰ�, ���ٸ� 0�� ����Ѵ�.

�ذ� ��� : �־��� ���� ������ �� ĭ�� ���� ���� ������ ��Ʈ����ŷ ���·� �ٲ۴�. �� �������� 1, 1�������� BFS�� �ϸ� �ȴ�.
BFS�� �� ������ �̵� ���⿡�� ���� �ִ����� �߰��� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��Ʈ����ŷ

��ó : JDC 2010 B��
*/

int walls[32][32], vis[32][32], dist[32][32]; //walls : 1 R 2 D 4 L 8 U
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<pair<int, int>> q;
int w = 0, h = 0;

int isvalid(int x, int y, int d) {
    if (walls[x][y] & (1 << d)) return 0;
    int x2 = x + dxy[d][0];
    int y2 = y + dxy[d][1];
    if (x2 < 0 || y2 < 0 || x2 >= h || y2 >= w) return 0;
    if (vis[x2][y2]) return 0;
    return 1;
}

int bfs(int x, int y) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    dist[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x, y, i)) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
    return dist[h - 1][w - 1];
}

int main(void) {
    int x;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                vis[i][j] = 0;
                dist[i][j] = 0;
                walls[i][j] = 0;
            }
        }
        for (int i = 0; i < h * 2 - 1; i++) {
            for (int j = 0; j < w - (!(i & 1)); j++) {
                scanf("%d", &x);
                if (!x) continue;
                if (i & 1) {
                    walls[i >> 1][j] |= 2;
                    walls[(i + 1) >> 1][j] |= 8;
                }
                else {
                    walls[i >> 1][j] |= 1;
                    walls[i >> 1][j + 1] |= 4;
                }
            }
        }
        printf("%d\n", bfs(0, 0));
    }
    return 0;
}