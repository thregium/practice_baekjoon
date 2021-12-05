#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : H * W(H, W <= 100) 크기의 체스판에서 (1, 1)부터 (i, j)까지 가는데 드는 나이트의 이동 횟수를 구한다.
없다면 "NEVAR"를 출력한다.

해결 방법 : BFS를 통해 각 칸별로 이동의 최단거리를 구한다. (i, j)에 방문한 적이 없다면 NEVAR를 출력하고,
있다면 최단거리를 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : LvOI 10II 2번
*/

int vis[128][128], dist[128][128];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > h || y > w) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    int d;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        for (int i = 0; i < 8; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int i, j;
    scanf("%d %d %d %d", &h, &w, &i, &j);
    bfs(1, 1);
    if (vis[i][j]) printf("%d", dist[i][j]);
    else printf("NEVAR");
    return 0;
}