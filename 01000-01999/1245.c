#include <stdio.h>

/*
문제 : N(N <= 100) * M(M <= 70)의 격자에서 산봉우리의 개수를 구한다. 산봉우리는 주위 상하좌우대각선으로 더 높은 칸이 없는
인접하고 높이가 같은 칸들의 집합이다.

해결 방법 : 플러드필을 이용하여 높이가 같고 인접한 칸들에 대해 방문 처리를 하며 더 높은 칸이 없는지 살펴본다.
없다면 해당 칸들은 봉우리인 것이므로 결괏값에 추가하고, 있다면 방문 처리만 하고 넘어간다. 이미 방문 처리된 칸은
살피지 않고 넘어가면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2008N B2번
*/

int height[128][128], vis[128][128];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int n, m;

int isvalid(int x, int y, int h) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (height[x][y] > h) return -1;
    if (vis[x][y] || height[x][y] < h) return 0;
    return 1;
}

int dfs(int x, int y, int h, int r) {
    //r = 1 : 주위에 더 높은 봉우리가 없음, 0 : 주위에 더 높은 봉우리가 있음
    int v;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        v = isvalid(x + dxy[i][0], y + dxy[i][1], h);
        if (v < 0) r = 0;
        else if (v > 0) r = dfs(x + dxy[i][0], y + dxy[i][1], h, r);
    }
    return r;
}

int main(void) {
    int r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &height[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                r += dfs(i, j, height[i][j], 1);
            }
        }
    }
    printf("%d", r);
    return 0;
}