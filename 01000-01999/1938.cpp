#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : N * N(N <= 50) ũ���� ĭ���� 1 * 3 ũ���� �볪���� �ű���� �Ѵ�. �볪���� �����¿�� �̵� �����ϸ�,
��ֹ��� �ִ� �����δ� �ű� �� ����. ���� ��ó 3 * 3 ������ ��� �ִٸ� �볪���� 90�� ȸ�� �����ϴ�.
�̶�, ������ ������ �־����� ��������� �������� �볪���� �ű�µ� �ʿ��� �ð��� ���Ѵ�.
�����¿� �̵� �Ǵ� ȸ���ø��� �ð��� 1�� �ҿ�ȴ�.

�ذ� ��� : BFS�� ���� ���� ã�Ƴ����� �ȴ�. X��ǥ, Y��ǥ, ������ ������ �ϰ� ������� �������� �Է¿��� ã�� ����,
�� �̵��� �������� Ȯ���ϸ� �ִ� �Ÿ��� ã�� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ���� 1998 ��2��
*/

char terrain[64][64], vis[64][64][2];
int dist[64][64][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
queue<tuple<int, int, int>> q; //x, y, d(0: ����, 1: ����)

int isvalid(int x, int y, int d) {
    if (d == 0) {
        if (x < 1 || y < 0 || x >= n - 1 || y >= n) return 0;
        if (vis[x][y][d]) return 0;
        if (terrain[x][y] == '1' || terrain[x + 1][y] == '1' || terrain[x - 1][y] == '1') return 0;
        return 1;
    }
    else if (d == 1) {
        if (x < 0 || y < 1 || x >= n || y >= n - 1) return 0;
        if (vis[x][y][d]) return 0;
        if (terrain[x][y] == '1' || terrain[x][y + 1] == '1' || terrain[x][y - 1] == '1') return 0;
        return 1;
    }
    else {
        if (x < 1 || y < 1 || x >= n - 1 || y >= n - 1) return 0;
        if (vis[x][y][3 - d]) return 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (terrain[x + i][y + j] == '1') return 0;
            }
        }
        return 1;
    }
}

void bfs(int x, int y, int d) {
    q.push(make_tuple(x, y, d));
    vis[x][y][d] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], d)) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], d));
                vis[x + dxy[i][0]][y + dxy[i][1]][d] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][d] = dist[x][y][d] + 1;
            }
        }
        if (isvalid(x, y, 2 + d)) {
            q.push(make_tuple(x, y, !d));
            vis[x][y][!d] = 1;
            dist[x][y][!d] = dist[x][y][d] + 1;
        }
    }
}

int main(void) {
    int sx = -1, sy = 0, sd = 0, ex = -1, ey = 0, ed = 0, scnt = 0, ecnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", terrain[i]);
        for (int j = 0; j < n; j++) {
            if (terrain[i][j] == 'B') {
                scnt++;
                if (scnt == 2) {
                    sx = i;
                    sy = j;
                    if (terrain[i][j + 1] == 'B') sd = 1;
                    else sd = 0;
                }
            }
            else if (terrain[i][j] == 'E') {
                ecnt++;
                if (ecnt == 2) {
                    ex = i;
                    ey = j;
                    if (terrain[i][j + 1] == 'E') ed = 1;
                    else ed = 0;
                }
            }
        }
    }
    if (sx < 0 || ex < 0) return 1;

    bfs(sx, sy, sd);
    printf("%d\n", vis[ex][ey][ed] ? dist[ex][ey][ed] : 0);
    /*
    for (int h = 0; h <= 1; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", dist[i][j][h]);
            }
            printf("\n");
        }
        printf("\n");
    }
    */
    return 0;
}