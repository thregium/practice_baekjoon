#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : H * W(H, W <= 1000) 크기의 격자에서 'X'로 된 칸을 지나지 않고 상하좌우로 이동해 'S'부터 '1', '2', ...을 지나
'N(N <= 9)'으로 가는 최단거리를 구한다.

해결 방법 : BFS를 'S'에서 시작해 1, 1에서 시작해 2, ..., N - 1에서 시작해 N으로 차례로 이동하는 최단거리를 각각 구해서
각 거리를 더하면 답이 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : JOI 2011예 5번
*/

char fac[1024][1024];
int vis[1024][1024], dist[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<pair<int, int>> q;
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || fac[x][y] == 'X') return 0;
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
    int n, x = -1, y = -1, r = 0;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < h; i++) {
        scanf("%s", fac[i]);
    }
    for (int i = 0; i <= n; i++) {
        x = -1, y = -1;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if ((i == 0 && fac[j][k] == 'S') || fac[j][k] == i + '0') {
                    x = j;
                    y = k;
                    r += dist[j][k];
                }
                vis[j][k] = 0;
                dist[j][k] = 0;
            }
        }
        if (i == n) break;
        if (x < 0) return 1;
        bfs(x, y);
    }
    printf("%d", r);
    return 0;
}