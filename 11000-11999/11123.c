#include <stdio.h>

/*
문제 : H * W(H, W <= 100) 크기의 격자에 '#'과 '.'이 있다. '#'으로 된 연결 요소의 개수를 구한다.

해결 방법 : 각 방문하지 않은 '#'마다 플러드필을 하고, 플러드필을 한 횟수를 구하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : IDI 2009 G번
*/

char sheep[128][128];
int vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || sheep[x][y] == '.') return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", sheep[i]);
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
        r = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (sheep[i][j] == '#' && !vis[i][j]) {
                    dfs(i, j);
                    r++;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}