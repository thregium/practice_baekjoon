#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : 500 * 500 크기의 판에서 갈 수 없는 칸과 1의 비용이 없는 칸들의 목록이
직사각형의 형태로 양 끝 꼭짓점이 주어진다. 각 칸의 효과는 들어갈 때만 적용된다.
두 영역의 직사각형 개수는 최대 50개다.
이때, (0, 0)에서 (500, 500)에 가는 최소 비용을 구한다. 갈 수 없는 경우 -1을 출력한다.

해결 방법 : 각 칸들의 종류를 구한 다음, 0-1 BFS를 통해 (500, 500)의 최단 거리를 구하면 된다.
단, 각 칸들의 종류를 구할 때 직사각형의 방향에 유의한다.

주요 알고리즘 : 그래프 이론, 0-1BFS
*/

int area[512][512], vis[512][512], dist[512][512];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
deque<pair<int, int>> dq;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x > 500 || y > 500) return 0;
    else if (vis[x][y]) return 0;
    else if (area[x][y] == 2) return 0;
    else if (area[x][y] == 1) return -1;
    else return 1;
}

int bfs(int x, int y) {
    int d = 0, v;
    vis[x][y] = 0;
    dq.push_back(pair<int, int>(x, y));
    while (dq.size()) {
        x = dq.front().first;
        y = dq.front().second;
        d = dist[x][y];
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            v = isvalid(x + dxy[i][0], y + dxy[i][1]);
            if (!v) continue;
            if (v < 0) {
                dist[x + dxy[i][0]][y + dxy[i][1]] = d + 1;
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dq.push_back(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
            else {
                dist[x + dxy[i][0]][y + dxy[i][1]] = d;
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dq.push_front(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    if (!vis[500][500]) return -1;
    else return dist[500][500];
}

int main(void) {
    int n, m, x1, y1, x2, y2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x2 < x1) swap(&x1, &x2);
        if (y2 < y1) swap(&y1, &y2);
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                area[x][y] = 1;
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x2 < x1) swap(&x1, &x2);
        if (y2 < y1) swap(&y1, &y2);
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                area[x][y] = 2;
            }
        }
    }

    printf("%d", bfs(0, 0));
    return 0;
}