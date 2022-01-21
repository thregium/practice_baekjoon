#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : H * W(H, W <= 200) 크기의 궁전에 공주와 적 군사들이 있다. 각자는 벽이 아닌 칸으로
1번에 동서남북으로 1칸씩 움직이거나 움직이지 않을 수 있다. 이때, 공주가 적군들이 어떻게 움직이더라도
잡히지 않고 비밀통로에 도달 가능한 지 구한다. 단, 동시에 비밀통로 입구에 도달한 경우 도주에 실패한 것이다.
'@'는 공주(1개), '$'는 적군, '%'는 비밀통로 입구(1개), '#'는 벽, '.'는 빈 칸이다.

해결 방법 : 공주와 적군이 갈 수 있는 곳을 BFS를 통해 찾아나간다. 공주의 위치를 먼저 큐에 넣고
적군의 위치를 나중에 큐에 넣은 다음 BFS를 진행한다. 공주는 적군이 있을 가능성이
없는 곳으로만 이동해야 한다. 큐의 끝까지 진행한 다음 공주가 비밀통로 입구에 도달하였는지 살핀다.
그러하다면 적군보다 먼저 도달했는지 확인한다. 둘 다인 경우 도주에 성공한 것이고, 하나라도 아닌 경우
붙잡힌 것이다.

주요 알고리즘 : 그래프 이론, BFS

출처 : JAG 2016P B번
*/

char pal[256][256], visp[256][256], viss[256][256];
int distp[256][256], dists[256][256];
int h, w;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<pair<int, int>> q;

int isvalid(int x, int y, int m) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (pal[x][y] == '#' || viss[x][y]) return 0;
    if (!m && visp[x][y]) return 0;
    return 1;
}

void bfs() {
    int x, y, d, m = 0;
    while (q.size()) {
        x = q.front().first, y = q.front().second;
        if (x >= 256) {
            x -= 256, y -= 256, m = 0, d = distp[x][y];
        }
        else {
            m = 1, d = dists[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], m)) {
                if (m == 0) {
                    visp[x + dxy[i][0]][y + dxy[i][1]] = 1;
                    distp[x + dxy[i][0]][y + dxy[i][1]] = distp[x][y] + 1;
                    q.push(pair<int, int>(x + dxy[i][0] + 256, y + dxy[i][1] + 256));
                }
                else {
                    viss[x + dxy[i][0]][y + dxy[i][1]] = 1;
                    dists[x + dxy[i][0]][y + dxy[i][1]] = dists[x][y] + 1;
                    q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                }
            }
        }
    }
}

int main(void) {
    int x = -1, y = -1;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", pal[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (pal[i][j] == '@') {
                q.push(pair<int, int>(i + 256, j + 256));
                visp[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (pal[i][j] == '$') {
                q.push(pair<int, int>(i, j));
                viss[i][j] = 1;
            }
            else if (pal[i][j] == '%') {
                x = i;
                y = j;
            }
        }
    }

    bfs();
    if (!visp[x][y] || (viss[x][y] && dists[x][y] <= distp[x][y])) printf("No\n");
    else printf("Yes\n");

    return 0;
}