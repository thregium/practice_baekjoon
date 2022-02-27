#include <stdio.h>
#include <tuple>
#include <deque>
using namespace std;

/*
문제 : N * N(N <= 50) 크기의 방에 벽과 문 2개, 거울을 설치할 수 있는 위치들이 주어지면,
두 문 사이를 거울을 통해 볼 수 있게 하기 위해 거울을 최소 몇 개 설치해야 하는 지 구한다.
단, 거울은 45도 각도로만 설치 가능하다.

해결 방법 : 0-1 BFS를 통해 각 칸에 진입하는 방향 별로 설치해야 하는 거울 개수를 구해 나가며
시작한 문과 다른 문의 설치해야 하는 거울 개수 가운데 최솟값을 찾으면 된다.

주요 알고리즘 : 그래프 이론, 0-1 BFS
*/

char house[64][64], vis[64][64][4];
int dist[64][64][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
deque<tuple<int, int, int>> dq;

void bfs(int x, int y) {
    int d, xn, yn;
    for (int i = 0; i < 4; i++) {
        dq.push_back(make_tuple(x, y, i));
    }
    while (dq.size()) {
        x = get<0>(dq.front());
        y = get<1>(dq.front());
        d = get<2>(dq.front());
        dq.pop_front();
        xn = x + dxy[d][0];
        yn = y + dxy[d][1];
        if (xn < 0 || yn < 0 || xn >= n || yn >= n) continue;
        if (house[xn][yn] == '*') continue;
        if (house[xn][yn] == '!') {
            if (!vis[xn][yn][(d + 1) & 3]) {
                vis[xn][yn][(d + 1) & 3] = 1;
                dist[xn][yn][(d + 1) & 3] = dist[x][y][d] + 1;
                dq.push_back(make_tuple(xn, yn, (d + 1) & 3));
            }
            if (!vis[xn][yn][(d + 3) & 3]) {
                vis[xn][yn][(d + 3) & 3] = 1;
                dist[xn][yn][(d + 3) & 3] = dist[x][y][d] + 1;
                dq.push_back(make_tuple(xn, yn, (d + 3) & 3));
            }
        }
        if (!vis[xn][yn][d]) {
            vis[xn][yn][d] = 1;
            dist[xn][yn][d] = dist[x][y][d];
            dq.push_front(make_tuple(xn, yn, d));
        }
    }
}

int main(void) {
    int xs = -1, ys = -1, xe = -1, ye = -1, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", house[i]);
        for (int j = 0; j < n; j++) {
            if (house[i][j] == '#') {
                if (xs < 0) {
                    xs = i;
                    ys = j;
                }
                else {
                    xe = i;
                    ye = j;
                }
            }
        }
    }
    bfs(xs, ys);
    r = 103000;
    for (int i = 0; i < 4; i++) {
        if (vis[xe][ye][i] && dist[xe][ye][i] < r) r = dist[xe][ye][i];
    }
    if (r == 103000) return 1;
    printf("%d", r);
    return 0;
}