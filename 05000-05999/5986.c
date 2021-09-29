#include <stdio.h>

/*
문제 : N * N * N(N <= 100) 크기의 3차원 공간에서 소행성의 수를 구한다. 소행성은 '*'이 상하전후좌우로 인접한 덩어리이다.

해결 방법 : 모든 칸을 방문하며 아직 방문하지 않은 '*'마다 플러드필을 돌린 후, 플러드필을 돌린 횟수를 구하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2011O B3번
*/

char aste[128][128][128], vis[128][128][128];
int dxyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0} };
int n;

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= n || y >= n || z >= n) return 0;
    if (vis[x][y][z] || aste[x][y][z] == '.') return 0;
    return 1;
}

void dfs(int x, int y, int z) {
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) dfs(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]);
    }
}

int main(void) {
    int r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", aste[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (aste[i][j][k] == '*' && !vis[i][j][k]) {
                    dfs(i, j, k);
                    r++;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}