#include <stdio.h>

/*
문제 : M * N(M, N <= 100) 크기의 격고자에 'W'와 'B'로 이루어진 두 진영이 주어진다. 이때, 각 진영의 전투력은 각 모임의 전투력의
합과 같고, 각 모임의 전투력은 모임의 크기의 제곱과 같다고 한다. 상하좌우로 같은 진영이 있으면 모임이라 할 때,
두 진영의 전투력을 구한다.

해결 방법 : 플러드필을 이용해 아직 방문하지 않은 군사마다 연결 요소의 크기를 구하고 그 제곱을 하여 해당 진영의 전투력에 더한다.
전부 더한 다음 각 진영의 전투력을 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필
*/

char soli[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int sqr(int x) {
    return x * x;
}

int isvalid(int x, int y, char c) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || soli[x][y] != c) return 0;
    return 1;
}

int dfs(int x, int y, char c) {
    int r = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], c)) r += dfs(x + dxy[i][0], y + dxy[i][1], c);
    }
    return r;
}

int main(void) {
    int w = 0, b = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", soli[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (soli[i][j] == 'W') w += sqr(dfs(i, j, 'W'));
            else if (soli[i][j] == 'B') b += sqr(dfs(i, j, 'B'));
            else return 1;
        }
    }
    printf("%d %d", w, b);
    return 0;
}