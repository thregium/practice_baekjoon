#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : M * N(M, N <= 30) 크기의 격자에서 한 번의 이동에 한쪽 방향으로 M1, 다른 쪽 방향으로 M2칸 만큼 움직이는 것이 가능하다.
단, 이동시 격자 바깥으로 나가거나 0이나 2가 쓰인 칸으로는 이동 불가능하다. 이때, 3이 쓰인 칸에서 4가 쓰인 칸으로
이동하는데 최소 몇 회 이동이 필요한지 구한다. 반드시 이동이 가능한 경우만 주어진다.

해결 방법 : 먼저 각 이동 가능한 방향을 정리한 다음, BFS를 통해 3이 쓰인 칸에서 시작하는 최단거리를 각각 구한 다음,
4가 쓰인 곳까지의 거리를 구하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2007F B2번
*/

int lily[32][32], vis[32][32], dist[32][32], dxy[8][2];
int m, n;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (vis[x][y] || lily[x][y] != 1) return 0;
    return 1;
}

int bfs(int x, int y, int d, int xf, int yf) {
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        if (x == xf && y == yf) return d;
        for (int i = 0; i < 8; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
    return -1;
}

int main(void) {
    int m1, m2, xs = -1, ys = -1, xf = -1, yf = -1, r;
    scanf("%d %d %d %d", &m, &n, &m1, &m2);
    for (int i = 0; i < 8; i++) {
        if (i & 4) {
            if (i & 1) dxy[i][0] = m1;
            else dxy[i][0] = -m1;
            if (i & 2) dxy[i][1] = m2;
            else dxy[i][1] = -m2;
        }
        else {
            if (i & 1) dxy[i][0] = m2;
            else dxy[i][0] = -m2;
            if (i & 2) dxy[i][1] = m1;
            else dxy[i][1] = -m1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &lily[i][j]);
            if (lily[i][j] == 3) {
                lily[i][j] = 1;
                xs = i;
                ys = j;
            }
            else if (lily[i][j] == 4) {
                lily[i][j] = 1;
                xf = i;
                yf = j;
            }
        }
    }
    if (xs < 0 || xf < 0) return 1;

    r = bfs(xs, ys, 0, xf, yf);
    if (r < 0) return 2;
    printf("%d", r);
    return 0;
}