#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 1000) 크기의 칸에서 장애물의 위치가 주어진다. 이때, H * W 크기의 직사각형을
장애물이 있는 곳에 걸리지 않고 (Sr, Sc)에서 (Fr, Fc)로 이동시키는 방법이 있는지 구하고 있다면 최소 이동 횟수(상하좌우)를 구한다.
없다면 -1을 출력한다. 입력에서 직사각형이 처음 있는 장소에는 장애물이 없는 경우만 주어진다.

해결 방법 : BFS를 통해 장애물을 피해서 BFS를 하면 된다. 단, 장애물이 있는지 여부는 누적 합을 통해
최적화를 해야 시간 내로 풀 수 있다.

주요 알고리즘 : 그래프 이론, BFS, 누적 합
*/

int grid[1024][1024], vis[1024][1024], dist[1024][1024];
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x <= 0 || y <= 0 || x + h - 1 > n || y + w - 1 > m) return 0;
    if (vis[x][y] || (grid[x + h - 1][y + w - 1] - grid[x - 1][y + w - 1] - grid[x + h - 1][y - 1] + grid[x - 1][y - 1])) return 0;
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
    int sr, sc, fr, fc;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &grid[i][j]);
            grid[i][j] += grid[i][j - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) grid[j][i] += grid[j - 1][i];
    }
    scanf("%d %d %d %d %d %d", &h, &w, &sr, &sc, &fr, &fc);
    bfs(sr, sc);
    if (!vis[fr][fc]) printf("-1");
    else printf("%d", dist[fr][fc]);
    return 0;
}