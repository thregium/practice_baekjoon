#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : H * W(H, W <= 500) ũ���� ���ڿ� �� ĭ�� ���� ĭ���� �ִ�.
�̶�, ���� �� ĭ���� ���� ĭ�� �ݴ� �����θ� �̵��ϸ� ������ �Ʒ��� �� �� �̵��ϴ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : BFS�� ���� �Ÿ��� ã���� �ȴ�. �̶�, �� ��ġ�� ���� ��ġ ������ �� ���̸� �˾ƾ� �ϹǷ�
���� �Լ����� ���� ��ǥ�� �־�� �Կ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : JOI 2022��2 2��
*/

char carp[512][512], vis[512][512];
int dist[512][512];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0 || x2 >= h || y2 >= w) return 0;
    if (vis[x2][y2] || carp[x1][y1] == carp[x2][y2]) return 0;
    return 1;
}

int bfs(int x, int y) {
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x, y, x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
    if (vis[h - 1][w - 1]) return dist[h - 1][w - 1];
    else return -1;
}

int main(void) {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", carp[i]);
    }
    printf("%d\n", bfs(0, 0));
    return 0;
}