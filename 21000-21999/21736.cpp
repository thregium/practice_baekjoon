#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 600) 크기의 격자에서 I에서 출발해 상하좌우로 움직이며 만날 수 있는 P의 수를 구한다.
단, X인 지점으로는 갈 수 없다.

해결 방법 : I에서 플러드필을 통해 얻을 수 있는 영역 안의 P의 수를 구하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : 숙명여대 1회 C번
*/

char school[768][768], vis[768][768];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || school[x][y] == 'X') return 0;
    return 1;
}

int bfs(int x, int y) {
    int r = 0;
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        if (school[x][y] == 'P') r++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            }
        }
    }
    return r;
}

int main(void) {
    int x = -1, y = -1, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", school[i]);
        for (int j = 0; j < m; j++) {
            if (school[i][j] == 'I') {
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return 1;

    r = bfs(x, y);
    if (r) printf("%d", r);
    else printf("TT");
    return 0;
}