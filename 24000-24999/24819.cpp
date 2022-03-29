#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 100) 크기의 격자에 '0', '1', 'S', 'L', 'R', 'U', 'D'가 쓰여 있다.
'S'인 칸에서 시작하며 '0'인 칸으로는 움직일 수 있고, '1'인 칸으로는 움직일 수 없다.
다른 칸들은 그 칸에 쓰인 방향에서 오는 경우만 움직일 수 있다. 이때, 격자의 가장자리에 시간 T(T <= 200) 내로
도달하는 방법이 있다면 최단 시간을, 없다면 "NOT POSSIBLE"을 출력한다.

해결 방법 : BFS를 통해 'S'에서 이동하며 최단 거리를 구해나가다 가장자리에 T 내에 도달하는 지 알아보고,
그러하다면 그때의 거리를 확인해 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : VTH 2019 B번
*/

char wall[128][128], vis[128][128];
int dist[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char c[] = "LURD";
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y, int d) {
    int nx = x + dxy[d][0];
    int ny = y + dxy[d][1];
    if (nx < 0 || ny < 0 || nx >= h || ny >= w) return 0;
    if (vis[nx][ny] || !(wall[nx][ny] == '0' || wall[nx][ny] == c[d])) return 0;
    return 1;
}

int bfs(int x, int y) {
    int d;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        if (x == 0 || y == 0 || x == h - 1 || y == w - 1) return dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x, y, i)) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
    return 103000;
}

int main(void) {
    int t, x = -1, y = -1, r;
    scanf("%d %d %d", &t, &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", wall[i]);
        for (int j = 0; j < w; j++) {
            if (wall[i][j] == 'S') {
                x = i, y = j, wall[i][j] = '0';
            }
        }
    }
    if (x < 0) return 1;
    r = bfs(x, y);
    if (r > t) printf("NOT POSSIBLE");
    else printf("%d", r);
    return 0;
}