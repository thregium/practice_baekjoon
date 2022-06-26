#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N * M(N, M <= 100) ũ���� �̷��� �� ĭ�� -1 �Ǵ� 10000 ������ �ڿ����� ���� �ִ�.
������� �������� �־�����, ��������� ���������� �����¿� �̵������� -1�� ĭ�� ������ �ʰ�
�̵��� �� �ִ� �� Ȯ���ϰ� ������ ��� �� �ִ� �Ÿ� ��� ���� �ڿ����� ���� �ִ��� �����
���� �ִ��� ���Ѵ�. ������� �������� ���� ���� -1�� �ƴϴ�.

�ذ� ��� : BFS�� ���� �ִ� �Ÿ��� �����ϵ�, �� �������� �ִܰŸ����� ���� �� �ִ� ���� �ִ���
���̳��� ���α׷����� ���� ����� ������ �ȴ�. ��, �� �������� ����� ����(�̹� ť���� ����)
������ �ִ��� �������� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, DP

��ó : GKS 2013B B2��
*/

int mem[128][128], vis[128][128], vism[128][128];
int maze[128][128];
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    else if (maze[x][y] < 0) return 0;
    else if (vis[x][y]) return 0;
    else return 1;
}

void bfs(int x, int y) {
    vis[x][y] = 1;
    mem[x][y] = maze[x][y];
    q.push({ x, y });
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        vism[x][y] = 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                q.push({ x + dxy[i][0], y + dxy[i][1] });
            }
            if (!vism[x + dxy[i][0]][y + dxy[i][1]] &&
                mem[x][y] + maze[x + dxy[i][0]][y + dxy[i][1]] > mem[x + dxy[i][0]][y + dxy[i][1]]) {
                mem[x + dxy[i][0]][y + dxy[i][1]] = mem[x][y] + maze[x + dxy[i][0]][y + dxy[i][1]];
            }
        }
    }
}

int main(void) {
    int t, sx, sy, ex, ey;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &maze[i][j]);
                vis[i][j] = 0;
                vism[i][j] = 0;
                mem[i][j] = 0;
            }
        }
        bfs(sx, sy);
        if (!vis[ex][ey]) printf("Case #%d: Mission Impossible.\n", tt);
        else printf("Case #%d: %d\n", tt, mem[ex][ey]);
    }
    return 0;
}