#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N * N(N <= 100) ũ���� ���� ������ ����� �ִ�. (1, 1)�� �濡�� ���� �����ְ�,
�����¿�� ���� ���� ������ �̵��� ���� ���� �����ϴ�.
��ü M(M <= 20000)���� ����ġ�� �ְ�, �� �濡�� ����ġ�� ����� ���� ���� �� �� �ִ�.
�̶�, �� �� �ִ� ���� �ִ� ������ ���Ѵ�.

�ذ� ��� : (1, 1)���� ����Ͽ� ����� �̵��� ������. ���� �̵��� ����� BFS�� ����,
���� ���� �����δ� ���� �ʴ´�. �� ����, �� �濡�� �� �� �ִ� ����ġ�� ��� �Ҵ�.
�� ��� �̹� �湮�� ��� ������ ���� ���� ���� ��� �� ������ �湮�� �� �־��ٴ� �ǹ��̹Ƿ�
ť�� �� ���� ����ְ� �湮 ó���� �صд�. �̸� �ݺ��Ͽ� ���� �� Ƚ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2015D S1��
*/

int vis[128][128], light[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<pair<int, int>> ed[128][128];
queue<pair<int, int>> q;

int isvalid(int x, int y, int n) {
    if (x < 1 || y < 1 || x > n || y > n) return 0;
    if (!light[x][y]) return 0;
    if (vis[x][y]) return -1;
    return 1;
}

int bfs(int x, int y, int n) {
    int res = 1;
    light[x][y] = 1;
    vis[x][y] = 1;
    q.push({ x, y });
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], n) > 0) {
                q.push({ x + dxy[i][0], y + dxy[i][1] });
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            }
        }

        for (auto& i : ed[x][y]) {
            if (!light[i.first][i.second]) {
                light[i.first][i.second] = 1;
                res++;
                for (int j = 0; j < 4; j++) {
                    if (isvalid(i.first + dxy[j][0], i.second + dxy[j][1], n) < 0) {
                        q.push({ i.first, i.second });
                        vis[i.first][i.second] = 1;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main(void) {
    int n, m, a, b, c, d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ed[a][b].push_back({ c, d });
    }
    printf("%d", bfs(1, 1, n));
    return 0;
}