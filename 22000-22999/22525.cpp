#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : �������� ������� �� ���� ���� �ְ�, ��ֹ� N(N <= 300)���� �ִ�. �� �Ͽ� ��ֹ��� ���� ������ ĭ����
1ĭ�� �̵� �����ϴٸ� T(T <= 30)�� �ȿ� �� ��ġ���� �̵��� �� �ִ� ĭ�� ������ ���Ѵ�.
�� ĭ�� ��ǥ�� ���� 30 ������ �����̴�.

�ذ� ��� : ������ ĭ(�����¿�� (1, 1), (-1, -1) ����)�� ���� �迭�� ������ ��
�Ϲ����� BFS�� ����� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : JAG 2011D B��
*/

char block[256][256], vis[256][256], dist[256][256];
int dxy[6][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1} };
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (vis[x][y] || block[x][y]) return 0;
    return 1;
}


void bfs(int x, int y, int t) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (dist[x][y] == t) break;
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    while (q.size()) q.pop();
}

int main(void) {
    int n, t, x, y, r;
    while (1) {
        scanf("%d %d", &t, &n);
        if (t == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            block[x + 128][y + 128] = 1;
        }
        scanf("%d %d", &x, &y);
        bfs(x + 128, y + 128, t);

        r = 0;
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                r += vis[i][j];
                block[i][j] = 0;
                vis[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}