#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 정육각형 모양으로 된 게임 판이 있고, 장애물 N(N <= 300)개가 있다. 한 턴에 장애물이 없는 인접한 칸으로
1칸씩 이동 가능하다면 T(T <= 30)턴 안에 현 위치에서 이동할 수 있는 칸의 개수를 구한다.
각 칸의 좌표는 절댓값 30 이하의 정수이다.

해결 방법 : 인접한 칸(상하좌우와 (1, 1), (-1, -1) 방향)을 방향 배열에 저장한 후
일반적인 BFS와 비슷한 방식을 사용하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : JAG 2011D B번
*/

char block[256][256], vis[256][256], dist[256][256];
int dxy[6][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1} };
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (vis[x][y] || block[x][y]) return 0;
    return 1;
}


void bfs(int x, int y, int t) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (dist[x][y] == t) break;
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    while (q.size()) q.pop();
}

int main(void) {
    int n, t, x, y, r;
    while (1) {
        scanf("%d %d", &t, &n);
        if (t == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            block[x + 128][y + 128] = 1;
        }
        scanf("%d %d", &x, &y);
        bfs(x + 128, y + 128, t);

        r = 0;
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                r += vis[i][j];
                block[i][j] = 0;
                vis[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}