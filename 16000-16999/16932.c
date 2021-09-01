#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 0과 1이 쓰인 격자에서 1로 상하좌우 연결된 부분을 연결 요소라 할 때, 한 칸의 값을 바꾸어 만들 수 있는
가장 큰 연결 요소의 크기를 구한다. 단, 0과 1은 각각 1개 이상씩 있다.

해결 방법 : 당연히 1을 0으로 바꾸는 것 보다는 0을 1로 바꾸는 것이 연결 요소를 더 키울 수 있기 때문에 이득이다.
모든 연결요소의 크기를 구한 다음, 각 0마다 해당 0을 1로 바꾸었을 때 연결 요소의 크기를 각각 구하며 최댓값을 찾으면 된다.
이때 같은 연결 요소를 여러번 더하면 안 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 브루트 포스
*/

int shape[1024][1024], group[1024][1024], sizes[524288];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, g = 0;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (group[x][y]) return 0;
    return 1;
}

int dfs(int x, int y, int g) {
    int r = 1;
    group[x][y] = g;
    for (int i = 0; i < 4; i++) {
        if (shape[x + dxy[i][0]][y + dxy[i][1]] && !group[x + dxy[i][0]][y + dxy[i][1]]) r += dfs(x + dxy[i][0], y + dxy[i][1], g);
    }
    return r;
}

int main(void) {
    int r = 0, sz;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &shape[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (shape[i][j] && !group[i][j]) {
                g++;
                sizes[g] = dfs(i, j, g);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (shape[i][j]) continue;
            sz = sizes[group[i][j + 1]] + 1;
            if (group[i + 1][j] != group[i][j + 1]) sz += sizes[group[i + 1][j]];
            if (group[i][j - 1] != group[i][j + 1] && group[i][j - 1] != group[i + 1][j]) sz += sizes[group[i][j - 1]];
            if (group[i - 1][j] != group[i][j + 1] && group[i - 1][j] != group[i + 1][j] && group[i - 1][j] != group[i][j - 1]) sz += sizes[group[i - 1][j]];
            if (sz > r) r = sz;
        }
    }
    if (r == 0) r = n * m;
    printf("%d", r);
    return 0;
}