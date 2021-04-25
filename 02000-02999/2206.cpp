#include <stdio.h>
#include <queue>
using namespace std;

char mp[256][256], vis[256][256][32];
int dist[256][256][32];
int mon[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int hor[8][2] = { {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1} };
int k, w, h;
queue<pair<pair<int, int>, int>> q;

int isvalid(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (mp[x][y] || c > k || vis[x][y][c]) return 0;
    return 1;
}

int bfs(int x, int y) {
    int hc = 0;
    q.push(pair<pair<int, int>, int>(pair<int, int>(x, y), 0));
    vis[0][0][0] = 1;
    while (q.size()) {
        x = q.front().first.first;
        y = q.front().first.second;
        hc = q.front().second;
        q.pop();
        if (x == h - 1 && y == w - 1) return dist[x][y][hc];
        for (int i = 0; i < 8; i++) {
            if (isvalid(x + hor[i][0], y + hor[i][1], hc + 1)) {
                vis[x + hor[i][0]][y + hor[i][1]][hc + 1] = 1;
                dist[x + hor[i][0]][y + hor[i][1]][hc + 1] = dist[x][y][hc] + 1;
                q.push(pair<pair<int, int>, int>(pair<int, int>(x + hor[i][0], y + hor[i][1]), hc + 1));
            }
        }
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + mon[i][0], y + mon[i][1], hc)) {
                vis[x + mon[i][0]][y + mon[i][1]][hc] = 1;
                dist[x + mon[i][0]][y + mon[i][1]][hc] = dist[x][y][hc] + 1;
                q.push(pair<pair<int, int>, int>(pair<int, int>(x + mon[i][0], y + mon[i][1]), hc));
            }
        }
    }
    return -1;
}

int main(void) {
    scanf("%d%d %d", &k, &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    printf("%d", bfs(0, 0));
    return 0;
}