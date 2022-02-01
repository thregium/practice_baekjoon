#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : N * M(N, M <= 1000) 크기의 지도에서 상하좌우로 이동하며 1이 있는 칸(벽)을 K(K <= 10)회 이하로 지나며
맨 왼쪽 위에서 오른쪽 아래로 이동할 수 있는지 구하고, 있다면 그 때의 최단거리를 구한다.

해결 방법 : 방문 배열에 벽을 부순 횟수를 같이 저장한 후 BFS를 한다. 1인 칸을 만나면 벽을 부순 횟수를 1씩 늘리고,
K보다 커지면 갈 수 없는 것으로 취급한다.

주요 알고리즘 : 그래프 이론, BFS
*/

char map[1024][1024], vis[1024][1024][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, k;
queue<tuple<int, int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x <= 0 || y <= 0 || x > n || y > m) return 0;
    if (vis[x][y][z] || z > k) return 0;
    return map[x][y] - '0' + 1;
}

int bfs(int x, int y) {
    int b = 0, d = 1;
    q.push(make_tuple(x, y, b, d));
    vis[x][y][b] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        b = get<2>(q.front());
        d = get<3>(q.front());
        q.pop();
        if (x == n && y == m) return d;
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], b) == 1) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], b, d + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][b] = 1;
            }
            else if (isvalid(x + dxy[i][0], y + dxy[i][1], b + 1) == 2) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], b + 1, d + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][b + 1] = 1;
            }
        }
    }
    return -1;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }
    printf("%d", bfs(1, 1));
    return 0;
}