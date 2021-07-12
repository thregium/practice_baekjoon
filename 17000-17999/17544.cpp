#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : R * C(R, C <= 1000) 크기의 격자에서 높이들이 주어진다.(h <= 10^9), 여기서 최대 K(K <= R - 1) 칸에 다리를 놓을 수 있다면
도달하는 가장 낮은 높이를 최대한 높이려고 할 때 도달하는 가장 낮은 높이를 구한다. 다리는 칸 수만 맞다면 서로 떼서 놓아도 된다.
출발지는 가장 아랫줄이고 도착지는 가장 윗줄이다.

해결 방법 : 이분 탐색을 통해 해당 높이를 기준으로 했을 때 다리를 K칸 이하로 놓고 갈 수 있는지 확인한 다음
가능하다면 탐색 구간을 위쪽으로, 불가능하다면 아래쪽으로 잡아가며 값을 찾으면 된다. 다리를 K칸 이하로 갈 수 있는지는
0-1 BFS를 통해 맨 아래쪽 칸에서 출발해 맨 위쪽 칸들 중 가장 거리가 짧은 곳이 K 이하이면 된다.
거리는 목표 높이 이하일 때 1씩 증가한다.

주요 알고리즘 : 그래프 이론, 0-1 BFS, 이분 탐색

출처 : BAPC 2019P C번
*/

int maps[1024][1024], vis[1024][1024], dist[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
deque<pair<int, int>> dq;

int isvalid(int r, int c, int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int bfs(int r, int c, int h, int k) {
    dq.clear();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    for (int i = 0; i < c; i++) {
        vis[r - 1][i] = 1;
        if (maps[r - 1][i] >= h) {
            dq.push_front(pair<int, int>(r - 1, i));
        }
        else {
            dq.push_back(pair<int, int>(r - 1, i));
            dist[r - 1][i] = 1;
        }
    }

    int x, y, best = 123456789;
    while (dq.size()) {
        x = dq.front().first;
        y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            if (!isvalid(r, c, x + dxy[i][0], y + dxy[i][1])) continue;
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            if (maps[x + dxy[i][0]][y + dxy[i][1]] >= h) {
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y];
                dq.push_front(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
            else {
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
                dq.push_back(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }

    for (int i = 0; i < c; i++) {
        if (dist[0][i] < best) best = dist[0][i];
    }
    if (best <= k) return 1;
    else return 0;
}

int main(void) {
    int r, c, k, lo = 0, hi = 1012345678;
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &maps[i][j]);
        }
    }
    while (lo < hi) {
        if (bfs(r, c, (lo + hi + 1) >> 1, k)) {
            lo = ((lo + hi + 1) >> 1);
        }
        else {
            hi = ((lo + hi + 1) >> 1) - 1;
        }
    }
    printf("%d", lo);
    return 0;
}