#include <stdio.h>
#include <tuple>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 100) 크기의 공장에 로봇이 있다. 로봇은 명령 한번에 앞으로 1 ~ 3칸 움직이거나 왼쪽 또는 오른쪽으로 90도 회전할 수 있다.
이때, 로봇을 시작 위치, 방향에서 도착 위치, 방향으로 옮기는데 필요한 최소한의 명령 횟수를 구한다.

해결 방법 : BFS를 통해 원래 상태에서 목표 상태까지의 최단거리를 구하면 된다. 현재 로봇의 위치와 방향을 정점으로 놓으면 된다.
중간이 막혀있다면 도착지로 갈 수 있더라도 가는 것이 불가능함에 유의한다.

주요 알고리즘 : 그래프 이론, BFS, 구현

출처 : 정올 2005지 고3번
*/

int factory[128][128], vis[128][128][5], dist[128][128][5];
int dxy[5][2] = { {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int right[5] = { 0, 3, 4, 2, 1 }, left[5] = { 0, 4, 3, 1, 2 };
int m, n;
queue<tuple<int, int, int>> q;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (factory[x][y]) return -1;
    if (vis[x][y][d]) return 0;
    return 1;
}

void bfs(int x, int y, int d) {
    q.push(make_tuple(x, y, d));
    vis[x][y][d] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());
        q.pop();
        if (!vis[x][y][left[d]]) {
            q.push(make_tuple(x, y, left[d]));
            vis[x][y][left[d]] = 1;
            dist[x][y][left[d]] = dist[x][y][d] + 1;
        }
        if (!vis[x][y][right[d]]) {
            q.push(make_tuple(x, y, right[d]));
            vis[x][y][right[d]] = 1;
            dist[x][y][right[d]] = dist[x][y][d] + 1;
        }
        for (int i = 1; i <= 3; i++) {
            if (isvalid(x + dxy[d][0] * i, y + dxy[d][1] * i, d) == -1) break;
            if (isvalid(x + dxy[d][0] * i, y + dxy[d][1] * i, d) == 0) continue;
            q.push(make_tuple(x + dxy[d][0] * i, y + dxy[d][1] * i, d));
            vis[x + dxy[d][0] * i][y + dxy[d][1] * i][d] = 1;
            dist[x + dxy[d][0] * i][y + dxy[d][1] * i][d] = dist[x][y][d] + 1;
        }
    }
}

int main(void) {
    int x, y, d;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &factory[i][j]);
        }
    }
    scanf("%d %d %d", &x, &y, &d);
    bfs(x - 1, y - 1, d);
    scanf("%d %d %d", &x, &y, &d);
    printf("%d", dist[x - 1][y - 1][d]);
    return 0;
}