#include <stdio.h>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : H * W(H, W <= 30) 크기의 공간에 로봇이 맨 왼쪽 위에서 오른쪽을 보고 있다.
각 칸의 명령은 5가지 중 하나로, 직전, 우회전, 유턴, 좌회전, 정지의 5가지이다.
다른 명령을 실행하기 위해서는 p_i(1 <= p_i <= 9)만큼의 비용이 필요하다.
이때, 맨 오른쪽 아래 칸으로 이동하기 위해 지불해야 하는 최소 비용을 구한다.

해결 방법 : 각 칸과 로봇의 방향을 정점으로 하고, 시작점에서 출발하는 다익스트라를 통해 답을 구한다.
각 정점에서 모든 행동을 해 보면서 해당 칸에 있는 행동을 한 경우 비용 0으로 이동, 그 외 행동인 경우
해당 비용만큼으로 이동한다. 이 과정에서 방향과 좌표가 변하는 것에 유의한다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : JDC 2008 D번
*/

int board[32][32], dist[32][32][4], vis[32][32][4], price[5];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
//dist, x, y, dir
int h, w;

int isvalid(int* x, int* y, int* dir, int inst) {
    int nx, ny, ndir;
    ndir = *dir;
    if (inst == 1) ndir = ((ndir + 1) & 3);
    else if (inst == 2) ndir = ((ndir + 2) & 3);
    else if (inst == 3) ndir = ((ndir + 3) & 3);
    if (inst < 4) {
        nx = *x + dxy[ndir][0];
        ny = *y + dxy[ndir][1];
    }
    else {
        nx = *x;
        ny = *y;
    }
    *dir = ndir;
    *x = nx;
    *y = ny;

    if (nx < 0 || ny < 0 || nx >= h || ny >= w) return 0;
    if (vis[nx][ny][ndir]) return 0;
    else return 1;
}

int main(void) {
    int ndist, x, y, dir, nx, ny, ndir, res;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        for (int i = 0; i < 4; i++) {
            scanf("%d", &price[i]);
        }
        price[4] = INF;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < 4; k++) {
                    dist[i][j][k] = INF;
                    vis[i][j][k] = 0;
                }
            }
        }

        pq.push({ 0, 0, 0, 0 });
        dist[0][0][0] = 0;
        while (pq.size()) {
            ndist = get<0>(pq.top());
            x = get<1>(pq.top());
            y = get<2>(pq.top());
            dir = get<3>(pq.top());
            pq.pop();
            if (vis[x][y][dir]) continue;
            else vis[x][y][dir] = 1;

            for (int i = 0; i < 5; i++) {
                nx = x, ny = y, ndir = dir;
                if (isvalid(&nx, &ny, &ndir, i)) {
                    if (dist[nx][ny][ndir] > dist[x][y][dir] + (i == board[x][y] ? 0 : price[i])) {
                        dist[nx][ny][ndir] = dist[x][y][dir] + (i == board[x][y] ? 0 : price[i]);
                        pq.push({ dist[nx][ny][ndir], nx, ny, ndir });
                    }
                }
            }
        }

        res = INF;
        for (int i = 0; i < 4; i++) {
            if (dist[h - 1][w - 1][i] < res) res = dist[h - 1][w - 1][i];
        }
        printf("%d\n", res);
    }
    return 0;
}