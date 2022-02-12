#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 숫자가 쓰인 행렬에서 3개의 숫자(중복 가능)만을 지나
맨 윗 줄에서 맨 아랫 줄로 이동할 수 있는 경우 가운데 사전순으로 가장 빠른 3개의 숫자를 구한다.
그러한 경우가 없다면 -1을 3개 출력한다.

해결 방법 : 모든 경우에 대해 맨 윗 줄에서부터 브루트 포스를 하고 맨 아랫 줄에 도달하는 경우가 있는
가장 빠른 3개의 수를 출력한다. 모든 경우에 불가능한 경우 -1을 3개 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 브루트 포스

출처 : CCO 2005 1번
*/

int mat[128][128], vis[128][128], sel[4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y]) return 0;
    if (mat[x][y] == sel[0] || mat[x][y] == sel[1] || mat[x][y] == sel[2]) return 1;
    return 0;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < 10; i++) {
        sel[0] = i;
        for (int j = 0; j < 10; j++) {
            sel[1] = j;
            for (int k = 0; k < 10; k++) {
                sel[2] = k;
                for (int l = 0; l < m; l++) {
                    if (mat[0][l] == i || mat[0][l] == j || mat[0][l] == k) dfs(0, l);
                }
                for (int l = 0; l < m; l++) {
                    if (vis[n - 1][l]) {
                        printf("%d %d %d", sel[0], sel[1], sel[2]);
                        return 0;
                    }
                }
                for (int l = 0; l < n; l++) {
                    for (int o = 0; o < m; o++) vis[l][o] = 0;
                }
            }
        }
    }
    printf("-1 -1 -1");
    return 0;
}