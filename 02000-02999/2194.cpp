#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 500) 크기의 배열에 대해 장애물이 있는 K개의 칸을 피해
H * W(H, W <= 10) 크기의 직사각형을 시작점에서 끝점으로 옮기기 위해 필요한 최소 이동 횟수를 구한다.
불가능한 경우 -1을 출력한다.

해결 방법 : 누적 합 배열을 만든 다음, 직사각형의 위치에 대해 BFS를 한다. 탐색 시간을 절약하기 위해
누적 합을 사용하면 좋다(필수는 아니다).

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
    int k, x, y, sr, sc, fr, fc;
    scanf("%d %d %d %d %d", &n, &m, &h, &w, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        grid[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) grid[i][j] += grid[i][j - 1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) grid[j][i] += grid[j - 1][i];
    }
    scanf("%d %d %d %d", &sr, &sc, &fr, &fc);
    bfs(sr, sc);
    if (!vis[fr][fc]) printf("-1");
    else printf("%d", dist[fr][fc]);
    return 0;
}