#include <stdio.h>

/*
문제 : M * N(M, N <= 250) 크기의 칸에 1과 0이 있다.
이때, 1이 상하좌우대각선으로 연결된 연결 요소의 개수를 구한다.

해결 방법 : 각 방문하지 않은 연결요소마다 플러드필을 하고 그 횟수를 세면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : 충남대 1회 A번
*/

int a[256][256], vis[256][256];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int m, n;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > m || y > n) return 0;
    if (vis[x][y] || !a[x][y]) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j] || vis[i][j]) continue;
            dfs(i, j);
            r++;
        }
    }
    printf("%d", r);
    return 0;
}