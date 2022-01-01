#include <stdio.h>

/*
문제 : M * N(M, N <= 1000) 크기의 0과 1로 이루어진 격자에서 맨 위의 0 중 하나에서 상하좌우로 이동하며
1인 칸을 지나지 않고 맨 아래로 이동 가능한지 구한다.

해결 방법 : 플러드필을 이용하여 맨 위의 모든 0에서 상하좌우로 이동하며 갈 수 있는 모든 칸을 찾고,
그 가운데 맨 아래가 있는 지 찾으면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : Daejeon 2016 G번
*/

char grid[1024][1024], vis[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int m, n;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (vis[x][y] || grid[x][y] == '1') return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == '0') dfs(0, i);
    }
    for (int i = 0; i < n; i++) {
        if (vis[m - 1][i]) r = 1;
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}