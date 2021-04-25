#include <stdio.h>
#include <queue>
using namespace std;

int land[128][128], vis[128][128], dist[128][128];
int dxy[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int n;

queue<pair<int, int>> q;

int isedge(int x, int y) {
    int r = 0;
    for (int i = 0; i < 4; i++) {
        if (x + dxy[i][0] < 0 || y + dxy[i][1] < 0 || x + dxy[i][0] >= n || y + dxy[i][1] >= n) continue;
        if (!land[x + dxy[i][0]][y + dxy[i][1]]) r++;
    }
    return r;
}

int isvalid1(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || !land[x][y]) return 0;
    return 1;
}

int isvalid2(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (dist[x][y]) return 0;
    return 1;
}

void dfs(int x, int y, int p) {
    vis[x][y] = p;
    if (isedge(x, y)) {
        q.push(pair<int, int>(x, y));
    }

    if (isvalid1(x - 1, y)) dfs(x - 1, y, p);
    if (isvalid1(x, y - 1)) dfs(x, y - 1, p);
    if (isvalid1(x + 1, y)) dfs(x + 1, y, p);
    if (isvalid1(x, y + 1)) dfs(x, y + 1, p);
}

int bfs(int x, int y, int p) {
    
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid2(x + dxy[i][0], y + dxy[i][1]) && vis[x + dxy[i][0]][y + dxy[i][1]] != p) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
                if (land[x + dxy[i][0]][y + dxy[i][1]] != 0 && vis[x + dxy[i][0]][y + dxy[i][1]] != p) {
                    return dist[x][y];
                }
            }
        }
    }
    return 12345;
}

int main(void) {
    int p = 1, b = 12345, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &land[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] && !vis[i][j]) {
                dfs(i, j, p);
                x = bfs(i, j, p);
                if (x < b) b = x;
                p++;
                while(q.size()) q.pop();
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) dist[k][l] = 0;
                }
            }
        }
    }
    printf("%d", b);
    return 0;
}