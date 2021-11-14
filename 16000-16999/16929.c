#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 배열에 문자들이 있을 때, 상하좌우로 인접한 같은 문자로 이루어진
길이 4 이상의 사이클이 있는지 구한다.

해결 방법 : 배열의 각 원소에 대해 DFS를 시도한다. 만약 마지막에 이동한 방향의 반대가 아닌 방향에서 왔고
이미 방문한 칸을 방문하게 되면 길이 2가 아닌 사이클을 발견한 것이므로 Yes가 답이고,
그러한 적이 없다면 사이클이 없던 것이므로 No가 답이다.

주요 알고리즘 : 그래프 이론, DFS
*/

char s[64][64];
int vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y, char c) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (s[x][y] != c) return 0;
    if (vis[x][y]) return -1;
    return 1;
}

int dfs(int x, int y, int l) {
    vis[x][y] = 1;
    int t = 0, r = 0;
    for (int i = 0; i < 4; i++) {
        if (l == i) continue;
        t = isvalid(x + dxy[i][0], y + dxy[i][1], s[x][y]);
        if (t < 0) {
            return 1;
        }
        else if (t) r |= dfs(x + dxy[i][0], y + dxy[i][1], (i + 2) & 3);
    }
    return r;
}

int main(void) {
    int r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r |= dfs(i, j, -1);
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) vis[ii][jj] = 0;
            }
        }
    }
    printf("%s", r ? "Yes" : "No");
    return 0;
}