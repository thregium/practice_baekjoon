#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * N(N <= 200) 크기 보드에서 특정한 6개 방향으로 움직일 수 있는(방향 생략) 말이 있다.
이 말을 보드에서 나가지 않고 (R1, C1)에서 (R2, C2)로 움직일 수 있는지 확인하고 가능하다면 최소 이동 횟수를 구한다.

해결 방법 : BFS를 통해 R1, C1에서 시작해 모든 지점까지의 최단거리를 구한다. (R2, C2)에 방문한 적이 없다면 갈 수 없는 것이고,
방문한 적이 있다면 최단거리를 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS
*/

int vis[256][256], dist[256][256];
int dxy[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
}

int main(void) {
    int n, r1, c1, r2, c2;
    scanf("%d", &n);
    h = n, w = n;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    bfs(r1, c1);
    if (vis[r2][c2]) printf("%d", dist[r2][c2]);
    else printf("-1");
    return 0;
}