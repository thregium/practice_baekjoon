#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * N(N <= 1000) 크기의 지도와 물의 시작점 W(W <= N)개가 주어진다. (1, 1)에서
(N, N)으로 이동하기 위해 기다려야 하는 최소 날 수를 구한다. 돌이 있는 칸으로 상하좌우대각선으로
이동 가능하며, 시작점과 끝점을 제외하면 물이 있는 칸으로만 이동 가능하다. 이동시 시간은 걸리지 않는다.
물은 각 칸에서 상하좌우로 1일에 1칸씩 퍼져나간다.

해결 방법 : 우선 각 물의 시작점에서 BFS를 통해 각 지점에 물이 도달하는 시점을 구한다.
그리고 매개 변수 탐색과 플러드필을 이용하여 이동 가능한 하한을 찾으면 된다.

주요 알고리즘 : 그래프 이론, BFS, 파라메트릭

출처 : 가톨릭대 1회 G/5번
*/

char stone[1024][1024];
int dist[1024][1024], vis[1024][1024];
queue<pair<int, int>> q;
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int n;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y]) return 0;
    if (stone[x][y] == '0' || dist[x][y] > d) return -1;
    return 1;
}

int cango(int day) {
    int x, y, xn, yn;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) vis[i][j] = 0;
    }
    while (q.size()) q.pop();
    q.push({ 0, 0 });
    vis[0][0] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            xn = x + dxy[i][0];
            yn = y + dxy[i][1];
            if (xn == n - 1 && yn == n - 1) return 1;
            if (isvalid(xn, yn, day) > 0) {
                q.push({ xn, yn });
                vis[xn][yn] = 1;
            }
        }
    }
    return 0;
}

int main(void) {
    int w, x, y, lo = 0, hi = 2048, mid;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < w; i++) {
        scanf("%d %d", &x, &y);
        q.push({ x - 1, y - 1 });
        vis[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", stone[i]);
    }

    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i += 2) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], hi)) {
                q.push({ x + dxy[i][0], y + dxy[i][1] });
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }

    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (cango(mid)) hi = mid;
        else lo = mid + 1;
    }
    cango(lo);
    printf("%d", lo == 2048 ? -1 : lo);
    return 0;
}