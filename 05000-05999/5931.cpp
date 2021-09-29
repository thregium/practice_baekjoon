#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N * M(N, M <= 50) 크기의 격자에 '*'로 이루어진 두 덩어리가 있다. 두 덩어리를 하나로 뭉치기 위해 필요한
'*'의 개수를 구한다.  각 덩어리는 모든 '*'끼리 상하좌우로 이동이 가능한 '*'의 집합이다.

해결 방법 : 먼저 플러드필을 통해 두 덩어리의 위치를 찾는다. 그 다음, 첫 번째 덩어리에 있는 '*'의 위치를 전부 큐에 넣고
BFS를 돌린다. 이제 두 번째 덩어리에 있는 '*' 가운데 가장 첫 번째 덩어리와 같은 곳을 찾고, 그곳까지의 거리에서 1을 빼면
두 덩어리 사이의 거리가 되고, 그 경로로 '*'를 추가하면 한 덩어리가 되므로 이것이 답이 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2011N B4번
*/

char pattern[64][64];
int vis[64][64], dist[64][64], spot[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, pn = 1;
queue<pair<int, int>> q;

int isvalid(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if ((!c && vis[x][y]) || (c && spot[x][y]) || (c && pattern[x][y] == '.')) return 0;
    return 1;
}

void dfs(int x, int y) {
    spot[x][y] = pn;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], 1)) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

void bfs(void) {
    int x, y;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], 0)) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
}

int main(void) {
    int res = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", pattern[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pattern[i][j] == 'X' && !spot[i][j]) {
                dfs(i, j);
                pn++;
            }
            if (spot[i][j] == 1) {
                q.push(pair<int, int>(i, j));
                vis[i][j] = 1;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spot[i][j] == 2 && dist[i][j] < res) res = dist[i][j];
        }
    }
    if (res == INF) return 1;
    printf("%d", res - 1);
    return 0;
}