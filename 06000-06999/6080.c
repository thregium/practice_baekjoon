#include <stdio.h>

/*
문제 : R * C(R, C <= 1000) 크기의 격자에서 높이가 1 이상인 연결요소의 개수를 구한다. 각 칸은 상하좌우대각선으로 연결되어 있다.

해결 방법 : 각 방문하지 않은 높이가 1 이상인 지역마다 플러드필을 통해 연결요소에 대해 방문 처리를 한다.
플러드필을 한 횟수가 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2008D B2번
*/

int height[1024][1024], vis[1024][1024];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y] || height[x][y] == 0) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &height[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vis[i][j] || height[i][j] == 0) continue;
            dfs(i, j);
            res++;
        }
    }
    printf("%d", res);
    return 0;
}