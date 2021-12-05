#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 땅에 석유가 있는 칸과 없는 칸들이 주어진다.
석유를 모두 캐기 위해 뚫어야 하는 곳의 개수를 구한다. 상하좌우대각선으로 이어진 곳의 석유를 캘 수 있다.

해결 방법 : 플러드필을 통해 아직 탐사하지 않은 석유가 있는 칸마다 플러드필을 하며 플러드필을 한 횟수를 세면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : MidC 1997 A번
*/

char oil[128][128], vis[128][128];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || oil[x][y] != '@') return 0;
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
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", oil[i]);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && oil[i][j] == '@') {
                    dfs(i, j);
                    r++;
                }
            }
        }
        printf("%d\n", r);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}