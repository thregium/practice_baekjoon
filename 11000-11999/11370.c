#include <stdio.h>

/*
문제 : H * W 크기의 격자판에 'T'와 'S'들이 있을 때, 'S'와 상하좌우로 직간접적으로 인접한 'T'들을 'S'로 바꾸어 출력한다.

해결 방법 : 'S'들마다 플러드필을 시행하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : UVaH 2014 F번
*/

char wood[1024][1024], vis[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int w, h;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || (wood[x][y] != 'S' && wood[x][y] != 'T')) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", wood[i]);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (wood[i][j] == 'S') {
                    dfs(i, j);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%c", wood[i][j] != '.' ? (vis[i][j] ? 'S' : 'T') : '.');
                vis[i][j] = 0;
                wood[i][j] = '\0';
            }
            printf("\n");
        }
    }
    return 0;
}