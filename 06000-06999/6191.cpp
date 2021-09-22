#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : R * C(R <= 113, C <= 77) 크기의 미로가 주어질 때, 이 미로의 왼쪽 위에서 오른쪽 아래로 이동하는 경로를 출력한다.
반드시 경로가 있는 경우만 주어진다.

해결 방법 : 왼쪽 위에서 시작하는 BFS를 한 다음, 오른쪽 아래에서 경로를 역추적한다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2006X G3번
*/

char map[128][128], vis[128][128];
int path[16384][2], dist[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y] || map[x][y] != '.') return 0;
    return 1;
}

int isvalid2(int x, int y, int lx, int ly) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y] && dist[x][y] == dist[lx][ly] - 1) return 1;
    return 0;
}

void bfs(int x, int y) {
    int d = 0;
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        d = dist[x][y];
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = d + 1;
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
}

int main(void) {
    int x, y;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
    }
    bfs(0, 0);
    x = r - 1, y = c - 1;
    path[dist[x][y]][0] = x;
    path[dist[x][y]][1] = y;
    path[dist[x][y] + 1][0] = -1;
    while (x || y) {
        for (int i = 0; i < 4; i++) {
            if (isvalid2(x + dxy[i][0], y + dxy[i][1], x, y)) {
                path[dist[x][y] - 1][0] = x + dxy[i][0];
                path[dist[x][y] - 1][1] = y + dxy[i][1];
                x = x + dxy[i][0];
                y = y + dxy[i][1];
                break;
            }
        }
    }
    for (int i = 0; path[i][0] >= 0; i++) {
        printf("%d %d\n", path[i][0] + 1, path[i][1] + 1);
    }
    return 0;
}