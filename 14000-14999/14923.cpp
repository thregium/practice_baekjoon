#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : N * (N, M <= 1000) 크기의 0과 1로 이루어진 배열에서 (Hx, Hy)에서 출발하여 (Ex, Ey)로 이동하며
1인 곳을 최대 1회만 지나갈 수 있을 때의 최소 이동 횟수(상하좌우)를 구한다. 불가능한 경우 -1을 출력한다.

해결 방법 : BFS를 하되, 벽을 부수었는지 여부를 변수에 추가해 저장하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 홍익대 2017 F번
*/

int mp[1024][1024], vis[1024][1024][2], dist[1024][1024][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
deque<tuple<int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (vis[x][y][z]) return 0;
    if (mp[x][y] == 1) return -1;
    return 1;
}

void bfs(int x, int y) {
    int d, z, t;
    vis[x][y][0] = 1;
    q.push_back(make_tuple(x, y, 0));
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop_front();
        d = dist[x][y][z];
        for (int i = 0; i < 4; i++) {
            t = isvalid(x + dxy[i][0], y + dxy[i][1], z);
            if (!t) continue;
            if (t > 0) {
                q.push_back(make_tuple(x + dxy[i][0], y + dxy[i][1], z));
                vis[x + dxy[i][0]][y + dxy[i][1]][z] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z] = dist[x][y][z] + 1;
            }
            if (t < 0) {
                if (z > 0 || vis[x + dxy[i][0]][y + dxy[i][1]][z + 1]) continue;
                q.push_back(make_tuple(x + dxy[i][0], y + dxy[i][1], z + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][z + 1] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z + 1] = dist[x][y][z] + 1;
            }
        }
    }
}

int main(void) {
    int hx, hy, ex, ey, r = -1;
    scanf("%d %d%d %d%d %d", &n, &m, &hx, &hy, &ex, &ey);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    bfs(hx, hy);
    if (vis[ex][ey][0]) r = dist[ex][ey][0];
    if (vis[ex][ey][1]) {
        if (r < 0 || r > dist[ex][ey][1]) r = dist[ex][ey][1];
    }
    printf("%d", r);
    return 0;
}