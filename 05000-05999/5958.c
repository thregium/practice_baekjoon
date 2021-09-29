#include <stdio.h>

/*
문제 : N * N(N <= 1000) 크기의 격자판에 '*'로 이루어진 연결요소의 개수를 구한다.
각 연결요소는 상하좌우로 연결된 '*'의 묶음이다.

해결 방법 : 아직 방문하지 않은 '*'마다 플러드필을 통해 방문 처리를 하고 플러드필을 한 횟수를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2011J B3번
*/

char aste[1024][1024], vis[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || aste[x][y] == '.') return 0;
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
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", aste[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (aste[i][j] == '*' && !vis[i][j]) {
                r++;
                dfs(i, j);
            }
        }
    }
    printf("%d", r);
    return 0;
}