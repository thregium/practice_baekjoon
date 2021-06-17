#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 100) 크기의 격자에서 (1, 1)부터 (N, M)까지 벽을 거치지 않고 가거나
2가 있는 칸까지 벽을 거치지 않고 간 다음 (N, M)까지 벽을 거치는지와 상관 없이 갈 수 있다. 이 중 더 빠른 것의 이동 거리를 구한다.

해결 방법 : BFS를 통해 2가 있는 칸과 (N, M)까지의 거리를 각각 구하고 2가 있는 칸에서 (N, M)과의 맨해튼 거리를 더한 값과
(N, M)까지의 거리를 비교한다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 홍익대 2019 B번
*/

int castle[128][128], vis[128][128], dist[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, t;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (castle[x][y] == 1 || vis[x][y]) return 0;
    return 1;
}

int bfs(int x, int y) {
    int gdist = t + 1, pdist = t + 1;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (castle[x][y] == 2) gdist = dist[x][y] + n - x + m - y;
        if (x == n && y == m) pdist = dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
        }
    }
    if (gdist < pdist) return gdist;
    else return pdist;
}

int main(void) {
    int r;
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &castle[i][j]);
            if (i == 1 && j == 1 && castle[i][j] == 1) return 1;
            if (i == n && j == m && castle[i][j] == 1) return 2;
        }
    }
    r = bfs(1, 1);
    if (r > t) printf("Fail");
    else printf("%d", r);
    return 0;
}