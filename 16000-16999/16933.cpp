#include <stdio.h>
#include <tuple>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N * M(N, M <= 1000) 크기의 0과 1로 이루어진 배열이 있다. 홀수 번째 이동에만 1인 칸으로
이동 가능하고, 1인 칸으로는 최대 K(K <= 10)회만 들어갈 수 있다면, (1, 1)에서 (N, M)으로 이동하기 위해
이동을 최소 몇 회 해야 하는 지 구한다. 이동 불가능하다면 -1을 출력한다.
이동은 상하좌우와 제자리 멈춤이 있다. 멈춘 상태에서도 이동 횟수가 늘어난다.

해결 방법 : 각 위치와 1인 칸에 들어간 횟수, 1인 칸에 이동 가능한 지 여부를 정점으로 두고
BFS를 진행한다. 상태가 복잡한 편이므로 이동에 실수하지 않도록 주의한다.

주요 알고리즘 : 그래프 이론, BFS
*/

char wall[1024][1024], vis[1024][1024][16][2];
int dist[1024][1024][16][2];
int n, m, k;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<tuple<int, int, int, int>> q;

int isvalid(int x, int y, int z, int dn) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y][z][dn]) return 0;
    if (wall[x][y] == '1') {
        if ((z == k || !dn)) return 0;
        else return 2;
    }
    return 1;
}

int bfs(int x, int y, int z, int dn) {
    int t, r = INF;
    q.push(make_tuple(x, y, z, dn));
    vis[x][y][z][dn] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        dn = get<3>(q.front());
        q.pop();
        if (!vis[x][y][z][!dn]) {
            dist[x][y][z][!dn] = dist[x][y][z][dn] + 1;
            vis[x][y][z][!dn] = 1;
            q.push(make_tuple(x, y, z, !dn));
        }
        for (int i = 0; i < 4; i++) {
            t = isvalid(x + dxy[i][0], y + dxy[i][1], z, !dn);
            if (t) {
                dist[x + dxy[i][0]][y + dxy[i][1]][z + t - 1][!dn] = dist[x][y][z][dn] + 1;
                vis[x + dxy[i][0]][y + dxy[i][1]][z + t - 1][!dn] = 1;
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z + t - 1, !dn));
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 2; j++) {
            if (!vis[n - 1][m - 1][i][j]) continue;
            if (dist[n - 1][m - 1][i][j] < r) r = dist[n - 1][m - 1][i][j];
        }
    }
    if (r == INF) return -2;
    else return r;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", wall[i]);
    }
    printf("%d", bfs(0, 0, 0, 0) + 1);
    return 0;
}