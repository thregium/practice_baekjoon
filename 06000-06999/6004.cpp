#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : X * Y(X, Y <= 150) 크기의 체스판에서 '*'가 있는 칸을 지나지 않고 'K'에서 나이트를 움직여 'H'로 움직이는
최단 이동 횟수를 구한다.

해결 방법 : K에서 시작하는 BFS를 돌린 다음, H까지의 거리를 구하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2009N B2번
*/

char map[192][192];
int vis[192][192], dist[192][192];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
queue<pair<int, int>> q;
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || map[x][y] == '*') return 0;
    return 1;
}

void bfs(int x, int y, int d) {
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        for (int i = 0; i < 8; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int kx = -1, ky = -1, hx = -1, hy = -1;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'K') {
                kx = i;
                ky = j;
            }
            else if (map[i][j] == 'H') {
                hx = i;
                hy = j;
            }
        }
    }
    if (kx < 0 || hx < 0) return 1;
    bfs(kx, ky, 0);
    if (!vis[hx][hy]) return 2;
    printf("%d", dist[hx][hy]);
    return 0;
}