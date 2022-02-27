#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : 5 * 5 크기의 0 또는 1이 쓰인 판이 5개 있다. 이 판들을 원하는 순서와 방향으로 쌓은 다음,
만들어진 미로 가운데 한쪽 끝에서 다른쪽 끝으로 이동하는데 걸리는 시간이 최소인 것의
이동 시간을 구한다. 어떤 미로에서도 그것이 불가능한 경우 -1을 출력한다.

해결 방법 : 각 판을 회전 방향마다 만들어놓은 다음, 각 경우마다의 미로를 만들고 BFS를 통해
최단 이동거리가 가장 짧은 것을 찾으면 된다. 회전이 가능하다는 점 때문에
시작점과 끝점은 하나로 고정해도 된다.

주요 알고리즘 : 그래프 이론, BFS, 브루트 포스, 구현

출처 : BaaaaaaaaaaarkingDog
*/

int used[8], board[8][4][8][8], maze[8][8][8], vis[8][8][8], dist[8][8][8];
int r = 103000;
int dxy[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };
queue<tuple<int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= 5 || y >= 5 || z >= 5) return 0;
    else if (maze[x][y][z] == 0 || vis[x][y][z]) return 0;
    return 1;
}

int bfs(int x, int y, int z) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                vis[i][j][k] = 0;
                dist[i][j][k] = 0;
            }
        }
    }
    q.push(make_tuple(x, y, z));
    vis[x][y][z] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], z + dxy[i][2])) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z + dxy[i][2]));
                vis[x + dxy[i][0]][y + dxy[i][1]][z + dxy[i][2]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z + dxy[i][2]] = dist[x][y][z] + 1;
            }
        }
    }
    if (!vis[4][4][4]) return -1;
    else return dist[4][4][4];
}

void track(int h) {
    if (h == 5) {
        if (maze[0][0][0] == 0) return;
        int t = bfs(0, 0, 0);
        if (t >= 0 && t < r) r = t;
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (used[i]) continue;
        used[i] = 1;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    maze[h][k][l] = board[i][j][k][l];
                }
            }
            track(h + 1);
        }
        used[i] = 0;
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%d", &board[i][0][j][k]);
            }
        }
        for (int j = 1; j <= 3; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    board[i][j][k][l] = board[i][j - 1][l][4 - k];
                }
            }
        }
    }
    track(0);
    printf("%d", r == 103000 ? -1 : r);
    return 0;
}