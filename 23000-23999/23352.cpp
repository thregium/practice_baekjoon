#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * M(N, M <= 50) ũ���� ���ڿ��� 0�� ĭ�� ������ �ʰ� ���� �� �ִ� ���� �� ���(�ִܰ�� ���) ���,
�������� ������ ���� ���� ū ���� ���� ���Ѵ�. �������� ������ ���� �� �ִ�. ��ΰ� ���ٸ� 0�� ����Ѵ�.

�ذ� ��� : ��� �������� �ش� �������� �����Ͽ� �� �� �ִ� ��� ���������� �Ÿ��� ���ϰ�,
���� �� �Ÿ��� ���� ����ذ��� ���� ã�ư��� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���Ʈ ����

��ó : �װ��� 1ȸ E��
*/

int num[64][64], vis[64][64], dist[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || num[x][y] == 0) return 0;
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
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int bdist = -1, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (num[i][j] == 0) continue;
            bfs(i, j);

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (vis[x][y] && dist[x][y] > bdist) {
                        bdist = dist[x][y];
                        res = num[i][j] + num[x][y];
                    }
                    else if (vis[x][y] && dist[x][y] == bdist && res < num[i][j] + num[x][y]) res = num[i][j] + num[x][y];
                    vis[x][y] = 0;
                    dist[x][y] = 0;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}