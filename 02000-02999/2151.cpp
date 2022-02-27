#include <stdio.h>
#include <tuple>
#include <deque>
using namespace std;

/*
���� : N * N(N <= 50) ũ���� �濡 ���� �� 2��, �ſ��� ��ġ�� �� �ִ� ��ġ���� �־�����,
�� �� ���̸� �ſ��� ���� �� �� �ְ� �ϱ� ���� �ſ��� �ּ� �� �� ��ġ�ؾ� �ϴ� �� ���Ѵ�.
��, �ſ��� 45�� �����θ� ��ġ �����ϴ�.

�ذ� ��� : 0-1 BFS�� ���� �� ĭ�� �����ϴ� ���� ���� ��ġ�ؾ� �ϴ� �ſ� ������ ���� ������
������ ���� �ٸ� ���� ��ġ�ؾ� �ϴ� �ſ� ���� ��� �ּڰ��� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, 0-1 BFS
*/

char house[64][64], vis[64][64][4];
int dist[64][64][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
deque<tuple<int, int, int>> dq;

void bfs(int x, int y) {
    int d, xn, yn;
    for (int i = 0; i < 4; i++) {
        dq.push_back(make_tuple(x, y, i));
    }
    while (dq.size()) {
        x = get<0>(dq.front());
        y = get<1>(dq.front());
        d = get<2>(dq.front());
        dq.pop_front();
        xn = x + dxy[d][0];
        yn = y + dxy[d][1];
        if (xn < 0 || yn < 0 || xn >= n || yn >= n) continue;
        if (house[xn][yn] == '*') continue;
        if (house[xn][yn] == '!') {
            if (!vis[xn][yn][(d + 1) & 3]) {
                vis[xn][yn][(d + 1) & 3] = 1;
                dist[xn][yn][(d + 1) & 3] = dist[x][y][d] + 1;
                dq.push_back(make_tuple(xn, yn, (d + 1) & 3));
            }
            if (!vis[xn][yn][(d + 3) & 3]) {
                vis[xn][yn][(d + 3) & 3] = 1;
                dist[xn][yn][(d + 3) & 3] = dist[x][y][d] + 1;
                dq.push_back(make_tuple(xn, yn, (d + 3) & 3));
            }
        }
        if (!vis[xn][yn][d]) {
            vis[xn][yn][d] = 1;
            dist[xn][yn][d] = dist[x][y][d];
            dq.push_front(make_tuple(xn, yn, d));
        }
    }
}

int main(void) {
    int xs = -1, ys = -1, xe = -1, ye = -1, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", house[i]);
        for (int j = 0; j < n; j++) {
            if (house[i][j] == '#') {
                if (xs < 0) {
                    xs = i;
                    ys = j;
                }
                else {
                    xe = i;
                    ye = j;
                }
            }
        }
    }
    bfs(xs, ys);
    r = 103000;
    for (int i = 0; i < 4; i++) {
        if (vis[xe][ye][i] && dist[xe][ye][i] < r) r = dist[xe][ye][i];
    }
    if (r == 103000) return 1;
    printf("%d", r);
    return 0;
}