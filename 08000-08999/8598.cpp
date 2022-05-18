#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : H * W(H, W <= 1000) ũ���� �ʵ忡�� ����Ʈ�� 'z'���� ����� 'n'���� �̵��ϴ�
�ּ� �̵� Ƚ���� ���Ѵ�. �̵��� �Ұ����� ��� "NIE"�� ����Ѵ�. 'x'�� ĭ���δ� �̵��� �� ����.

�ذ� ��� : BFS�� ���� �ּ� �̵� Ƚ���� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : JPOI 2010 2-0��
*/

char field[1024][1024];
int vis[1024][1024], dist[1024][1024];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || field[x][y] == 'x') return 0;
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
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", field[i]);
        for (int j = 0; j < w; j++) {
            if (field[i][j] == 'z') {
                x1 = i;
                y1 = j;
            }
            else if (field[i][j] == 'n') {
                x2 = i;
                y2 = j;
            }
        }
    }
    if (x1 < 0) return 1;
    bfs(x1, y1);
    if (vis[x2][y2]) printf("%d", dist[x2][y2]);
    else printf("NIE");
    return 0;
}