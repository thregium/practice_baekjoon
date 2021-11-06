#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : (0, 0)에서 (X, Y)(|X|, |Y| <= 500)로 N(N <= 10000)개의 칸(|| <= 500)으로 가지 않고
상하좌우로 이동하는 최소 이동 횟수를 구한다.

해결 방법 : 일반적인 BFS와 비슷하게 하되, X좌표와 Y좌표에 500씩을 더해서 BFS를 하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2007D S3번
*/

char pond[1024][1024], vis[1024][1024];
int dist[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<int> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 1024 || y >= 1024) return 0;
    if (vis[x][y] || pond[x][y]) return 0;
    return 1;
}

void bfs(int x, int y, int d) {
    q.push(x * 1024 + y);
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front();
        y = (x & 1023);
        x >>= 10;
        d = dist[x][y];
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push((x + dxy[i][0]) * 1024 + (y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = d + 1;
            }
        }
    }
}

int main(void) {
    int x, y, n, a, b;
    scanf("%d %d %d", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        pond[a + 512][b + 512] = 1;
    }
    bfs(512, 512, 0);
    if (!vis[x + 512][y + 512]) return 1;
    printf("%d", dist[x + 512][y + 512]);
    return 0;
}