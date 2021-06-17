#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 1000) 크기의 지날 수 있는 곳과 없는 곳이 표시된 지도가 주어질 때, 시작 지점에서 모든 점까지의 이동거리를 각각 구한다.

해결 방법 :  BFS를 통해 모든 곳의 이동거리를 구하면 된다. 거리 배열을 사용하면 더 좋다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 서강대 2017M F번
*/

int map[1024][1024], vis[1024][1024], dist[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || !map[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int x = 0, y = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    bfs(x, y);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) printf("%d ", dist[i][j]);
            else if (map[i][j]) printf("-1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}