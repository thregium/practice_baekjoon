#include <stdio.h>
#include <deque>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : N * N(N <= 100) 크기의 격자에서 A와 B 사이를 이동할 때, 'x'를 거치지 않고 이동하는 방법 가운데
가장 적게 회전의 회전 수를 구한다. 항상 이동 가능한 경우만 주어진다.

해결 방법 : 0-1 BFS를 통해 'A'에서 출발해서 각 칸의 방향마다 최소 회전 횟수를 구한다.
'B'에 도착했을 때의 회전 수를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 0-1BFS

출처 : USACO 2007Q S2번
*/

char mp[128][128], vis[128][128][4];
int dist[128][128][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;
deque<tuple<int, int, int>> dq;

int small(int a, int b) {
    return a < b ? a : b;
}

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (mp[x][y] == 'x' || vis[x][y][d]) return 0;
    return 1;
}

int bfs(void) {
    int x = -1, y = -1, d, a = -1, b = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mp[i][j] == 'A') {
                x = i; //A를 찾아서 A의 위치를 저장한다.
                y = j;
                a = i;
                b = j;
            }
        }
    }
    if (x < 0) return -1;
    for (int i = 0; i < 4; i++) {
        dist[x][y][i] = 0; //A가 있는 곳의 거리를 0으로 초기화한다.
        dq.push_back(make_tuple(x, y, i));
    }

    while (dq.size()) {
        x = get<0>(dq.front());
        y = get<1>(dq.front());
        d = get<2>(dq.front());
        dq.pop_front();
        vis[x][y][d] = 1;
        if (mp[x][y] == 'B' && !(a == x && b == y)) {
            return dist[x][y][d]; //B가 나오면 그곳까지의 거리를 반환한다.
        }

        if (isvalid(x + dxy[d][0], y + dxy[d][1], d)) {
            //직진
            dq.push_front(make_tuple(x + dxy[d][0], y + dxy[d][1], d));
            dist[x + dxy[d][0]][y + dxy[d][1]][d] = small(dist[x + dxy[d][0]][y + dxy[d][1]][d], dist[x][y][d]);
        }
        if (isvalid(x, y, (d + 3) & 3)) {
            //우회전
            dq.push_back(make_tuple(x, y, (d + 3) & 3));
            dist[x][y][(d + 3) & 3] = small(dist[x][y][(d + 3) & 3], dist[x][y][d] + 1);
        }
        if (isvalid(x, y, (d + 1) & 3)) {
            //좌회전
            dq.push_back(make_tuple(x, y, (d + 1) & 3));
            dist[x][y][(d + 1) & 3] = small(dist[x][y][(d + 1) & 3], dist[x][y][d] + 1);
        }
        //유턴은 회전 수 낭비이므로 생각할 필요가 없다.
    }
    return -1;
}

int main(void) {
    scanf("%d", &h);
    w = h;
    for (int i = 0; i < h; i++) {
        scanf("%s", mp[i]);
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 4; k++) dist[i][j][k] = INF; //먼저 거리를 전부 무한대로 초기화한다.
        }
    }
    printf("%d", bfs());
    return 0;
}