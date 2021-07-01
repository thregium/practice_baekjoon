#include <stdio.h>

/*
문제 : H * W(H, W <= 20) 크기의 격자에 검은 칸과 빨간 칸, 출발 지점의 위치가 주어질 때, 출발 지점에서 빨간 칸을 가지 않고
갈 수 있는 칸의 수를 구한다.

해결 방법 : 시작 지점에서 플러드필을 통해 풀 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : JDome 2004 B번
*/

int w, h;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char a[32][32], vis[32][32];

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || a[x][y] == '#') return 0;
    return 1;
}

dfs(int x, int y, int c) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) c += dfs(x + dxy[i][0], y + dxy[i][1], 1);
    }
    return c;
}

int main(void) {
    int x = 0, y = 0;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", a[i]);
            for (int j = 0; j < w; j++) {
                if (a[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d\n", dfs(x, y, 1));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
    }
    return 0;
}