#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : N * N(N <= 200) 크기의 격자에 K(K <= 1000)가지의 바이러스가 있다. 각 바이러스들은 매 초마다 주변 지역으로 퍼져나간다.
단, 이미 다른 바이러스가 있는 칸으로는 퍼지지 않는다. 매 초마다 퍼지는 순서는 바이러스의 번호 순서이다.
이때, S(S <= 10000)초 후 (X, Y)에 있는 바이러스의 종류를 구한다. 없다면 0을 출력한다.

해결 방법 : 각 바이러스들을 번호 순으로 큐에 담은 다음, BFS를 한다. (X, Y)에 있는 바이러스가 없거나
도달 시각이 S보다 크다면 바이러스가 없는 것이므로 0을 출력하고, 그 외에는 그 칸의 바이러스를 출력하면 된다.
같은 종류의 바이러스가 여러 칸에 있을 수 있음에 유의한다.

주요 알고리즘 : 그래프 이론, BFS
*/

int vis[256][256], dist[256][256];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
queue<tuple<int, int, int>> q;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    int v, d;
    while (q.size()) {
        v = get<0>(q.front());
        x = get<1>(q.front());
        y = get<2>(q.front());
        q.pop();
        d = dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(make_tuple(v, x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = v;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int k, s, x, y;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &vis[i][j]);
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (vis[j][k] == i) q.push(make_tuple(i, j, k));
            }
        }
    }
    bfs(0, 0);
    scanf("%d %d %d", &s, &x, &y);
    if (!vis[x][y] || dist[x][y] > s) printf("0");
    else printf("%d", vis[x][y]);
    return 0;
}