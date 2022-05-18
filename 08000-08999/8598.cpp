#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : H * W(H, W <= 1000) 크기의 필드에서 나이트가 'z'에서 출발해 'n'으로 이동하는
최소 이동 횟수를 구한다. 이동이 불가능한 경우 "NIE"를 출력한다. 'x'인 칸으로는 이동할 수 없다.

해결 방법 : BFS를 통해 최소 이동 횟수를 구한다.

주요 알고리즘 : 그래프 이론, BFS

출처 : JPOI 2010 2-0번
*/

char field[1024][1024];
int vis[1024][1024], dist[1024][1024];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || field[x][y] == 'x') return 0;
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
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", field[i]);
        for (int j = 0; j < w; j++) {
            if (field[i][j] == 'z') {
                x1 = i;
                y1 = j;
            }
            else if (field[i][j] == 'n') {
                x2 = i;
                y2 = j;
            }
        }
    }
    if (x1 < 0) return 1;
    bfs(x1, y1);
    if (vis[x2][y2]) printf("%d", dist[x2][y2]);
    else printf("NIE");
    return 0;
}