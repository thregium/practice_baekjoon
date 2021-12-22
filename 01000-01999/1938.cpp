#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : N * N(N <= 50) 크기의 칸에서 1 * 3 크기의 통나무를 옮기려고 한다. 통나무는 상하좌우로 이동 가능하며,
장애물이 있는 곳으로는 옮길 수 없다. 만약 근처 3 * 3 범위가 비어 있다면 통나무를 90도 회전 가능하다.
이때, 지형의 정보가 주어지면 출발지에서 목적지로 통나무를 옮기는데 필요한 시간을 구한다.
상하좌우 이동 또는 회전시마다 시간은 1씩 소요된다.

해결 방법 : BFS를 통해 답을 찾아나가면 된다. X좌표, Y좌표, 방향을 변수로 하고 출발지와 목적지를 입력에서 찾은 다음,
각 이동이 가능한지 확인하며 최단 거리를 찾을 수 있다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 정올 1998 고2번
*/

char terrain[64][64], vis[64][64][2];
int dist[64][64][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
queue<tuple<int, int, int>> q; //x, y, d(0: 세로, 1: 가로)

int isvalid(int x, int y, int d) {
    if (d == 0) {
        if (x < 1 || y < 0 || x >= n - 1 || y >= n) return 0;
        if (vis[x][y][d]) return 0;
        if (terrain[x][y] == '1' || terrain[x + 1][y] == '1' || terrain[x - 1][y] == '1') return 0;
        return 1;
    }
    else if (d == 1) {
        if (x < 0 || y < 1 || x >= n || y >= n - 1) return 0;
        if (vis[x][y][d]) return 0;
        if (terrain[x][y] == '1' || terrain[x][y + 1] == '1' || terrain[x][y - 1] == '1') return 0;
        return 1;
    }
    else {
        if (x < 1 || y < 1 || x >= n - 1 || y >= n - 1) return 0;
        if (vis[x][y][3 - d]) return 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (terrain[x + i][y + j] == '1') return 0;
            }
        }
        return 1;
    }
}

void bfs(int x, int y, int d) {
    q.push(make_tuple(x, y, d));
    vis[x][y][d] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], d)) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], d));
                vis[x + dxy[i][0]][y + dxy[i][1]][d] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][d] = dist[x][y][d] + 1;
            }
        }
        if (isvalid(x, y, 2 + d)) {
            q.push(make_tuple(x, y, !d));
            vis[x][y][!d] = 1;
            dist[x][y][!d] = dist[x][y][d] + 1;
        }
    }
}

int main(void) {
    int sx = -1, sy = 0, sd = 0, ex = -1, ey = 0, ed = 0, scnt = 0, ecnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", terrain[i]);
        for (int j = 0; j < n; j++) {
            if (terrain[i][j] == 'B') {
                scnt++;
                if (scnt == 2) {
                    sx = i;
                    sy = j;
                    if (terrain[i][j + 1] == 'B') sd = 1;
                    else sd = 0;
                }
            }
            else if (terrain[i][j] == 'E') {
                ecnt++;
                if (ecnt == 2) {
                    ex = i;
                    ey = j;
                    if (terrain[i][j + 1] == 'E') ed = 1;
                    else ed = 0;
                }
            }
        }
    }
    if (sx < 0 || ex < 0) return 1;

    bfs(sx, sy, sd);
    printf("%d\n", vis[ex][ey][ed] ? dist[ex][ey][ed] : 0);
    /*
    for (int h = 0; h <= 1; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", dist[i][j][h]);
            }
            printf("\n");
        }
        printf("\n");
    }
    */
    return 0;
}