#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : H * W(H, W <= 500) 크기의 격자에 흰 칸과 검은 칸들이 있다.
이때, 왼쪽 위 칸에서 현재 칸과 반대 색으로만 이동하며 오른쪽 아래로 갈 때 이동하는 최소 횟수를 구한다.

해결 방법 : BFS를 통해 거리를 찾으면 된다. 이때, 현 위치와 다음 위치 사이의 색 차이를 알아야 하므로
결정 함수에서 현재 좌표도 넣어야 함에 유의한다.

주요 알고리즘 : 그래프 이론, BFS

출처 : JOI 2022예2 2번
*/

char carp[512][512], vis[512][512];
int dist[512][512];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0 || x2 >= h || y2 >= w) return 0;
    if (vis[x2][y2] || carp[x1][y1] == carp[x2][y2]) return 0;
    return 1;
}

int bfs(int x, int y) {
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x, y, x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
    if (vis[h - 1][w - 1]) return dist[h - 1][w - 1];
    else return -1;
}

int main(void) {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", carp[i]);
    }
    printf("%d\n", bfs(0, 0));
    return 0;
}