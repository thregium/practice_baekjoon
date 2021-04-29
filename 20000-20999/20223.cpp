#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : N * N(N <= 50) 격자에서 0인 칸에서 출발해서 K + 1(K <= 5)인 칸까지 이동하는데 걸리는 최소 시간을 구한다.
단, 0부터 K까지 모든 자연수를 순서대로 지나야 하며, 격자 밖이나 #인 칸으로 이동할 수 없다.
또한, 이전에 이동한 변위에서 +-1만큼만 새로운 변위로 할 수 있다. 그리고, 도착시 변위는 0, 0이어야 한다.

해결 방법 : 큐에 위치와 함께 변위와 지금까지 지난 수들, 현재까지의 거리를 전부 집어넣는다.
또한, 방문 배열에도 위의 내용들 중 시간을 제외한 나머지를 전부 집어넣는다. 이때, 변위는 최대 9까지밖에 될 수 없으므로
(1 ~ 10까지 순서대로 더하면 50을 넘어가기 때문에), 방문 배열에 들어갈 수를 전부 더하더라도 최대 약 600만밖에 되지 않는다.
변위는 양수가 되어야 하므로 방문 배열에서는 9나 10을 더해주어야 한다.
BFS를 할 때에는 이전의 좌표에 2중 for문으로 이전의 변위에서 각각 -1 ~ +1 범위의 수를 더한 값을 더해준 값을 다음 좌표로 하면 된다.
또, 현재 찾을 수를 찾은 경우 지금까지의 수에 1을 더하고, K + 1이 나온 경우 탐색을 종료한다. 그 외에는 일반적인 BFS처럼 하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 구현

출처 : BAPC 2020P K번
*/

char grid[64][64], vis[50][50][20][20][6];
int r, c, k;
queue<tuple<int, int, int, int, int, int>> q; //x, y, dx, dy, dist, warn

int isvalid(int x, int y, int dx, int dy, int warn) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y][10 + dx][10 + dy][warn] || grid[x][y] == '#') return 0;
    return 1;
}

int bfs(int x, int y) {
    int dx, dy, dist, warn;
    q.push(make_tuple(x, y, 0, 0, 0, 0));
    vis[x][y][10][10][0] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        dx = get<2>(q.front());
        dy = get<3>(q.front());
        dist = get<4>(q.front());
        warn = get<5>(q.front());
        q.pop();
        if (grid[x][y] - '0' == k + 1 && warn == k && dx == 0 && dy == 0) {
            //종료 조건
            return dist;
        }
        else if (grid[x][y] - '0' - 1 == warn && grid[x][y] - '0' <= k) warn++; //현재 찾을 수를 찾은 경우
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (isvalid(x + dx + i, y + dy + j, dx + i, dy + j, warn)) {
                    q.push(make_tuple(x + dx + i, y + dy + j, dx + i, dy + j, dist + 1, warn));
                    vis[x + dx + i][y + dy + j][10 + dx + i][10 + dy + j][warn] = 1;
                }
            }
        }
    }
    return -1; //답을 찾지 못한 경우
}

int main(void) {
    int x = 0, y = 0, res;
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }
    res = bfs(x, y); //0에서 시작
    if (res < 0) printf("impossible");
    else printf("%d", res);
    return 0;
}