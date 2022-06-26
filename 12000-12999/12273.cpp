#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N * M(N, M <= 100) 크기의 미로의 각 칸에 -1 또는 10000 이하의 자연수가 쓰여 있다.
출발점과 도착점이 주어지면, 출발점에서 도착점으로 상하좌우 이동만으로 -1인 칸을 지나지 않고
이동할 수 있는 지 확인하고 가능한 경우 그 최단 거리 가운데 쓰인 자연수의 합이 최대인 경우의
합의 최댓값을 구한다. 출발점과 도착점에 쓰인 수는 -1이 아니다.

해결 방법 : BFS를 통해 최단 거리를 구성하되, 각 정점까지 최단거리에서 얻을 수 있는 힘의 최댓값을
다이나믹 프로그래밍을 통해 계산해 나가면 된다. 단, 이 과정에서 계산이 끝난(이미 큐에서 나온)
정점의 최댓값을 갱신하지 않음에 주의한다.

주요 알고리즘 : 그래프 이론, BFS, DP

출처 : GKS 2013B B2번
*/

int mem[128][128], vis[128][128], vism[128][128];
int maze[128][128];
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    else if (maze[x][y] < 0) return 0;
    else if (vis[x][y]) return 0;
    else return 1;
}

void bfs(int x, int y) {
    vis[x][y] = 1;
    mem[x][y] = maze[x][y];
    q.push({ x, y });
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        vism[x][y] = 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                q.push({ x + dxy[i][0], y + dxy[i][1] });
            }
            if (!vism[x + dxy[i][0]][y + dxy[i][1]] &&
                mem[x][y] + maze[x + dxy[i][0]][y + dxy[i][1]] > mem[x + dxy[i][0]][y + dxy[i][1]]) {
                mem[x + dxy[i][0]][y + dxy[i][1]] = mem[x][y] + maze[x + dxy[i][0]][y + dxy[i][1]];
            }
        }
    }
}

int main(void) {
    int t, sx, sy, ex, ey;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &maze[i][j]);
                vis[i][j] = 0;
                vism[i][j] = 0;
                mem[i][j] = 0;
            }
        }
        bfs(sx, sy);
        if (!vis[ex][ey]) printf("Case #%d: Mission Impossible.\n", tt);
        else printf("Case #%d: %d\n", tt, mem[ex][ey]);
    }
    return 0;
}