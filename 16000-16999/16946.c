#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기 격자에서 0은 빈 칸, 1은 벽이라 할 때, 모든 벽마다 해당 벽을 부수면 나오는
공간의 크기를 각각 구한다.

해결 방법 : 플러드필을 통해 각 빈 칸들의 연결 요소의 크기를 구한 다음, 모든 벽마다 주변 연결 요소들을 확인한다.
그 다음, 겹치지 않는 연결요소끼리 공간의 크기를 더하고 1을 더하면 그것이 해당 벽을 부수면 나오는 공간의 크기이다.

주요 알고리즘 : 그래프 이론, 플러드필
*/

char map[1024][1024], res[1024][1024];
int group[1024][1024], sizes[524288];
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
        if (map[x + dxy[i][0]][y + dxy[i][1]] == '0' && !group[x + dxy[i][0]][y + dxy[i][1]]) r += dfs(x + dxy[i][0], y + dxy[i][1], g);
    }
    return r;
}

int main(void) {
    int sz;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '0' && !group[i][j]) {
                g++;
                sizes[g] = dfs(i, j, g);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '0') {
                res[i - 1][j - 1] = '0';
                continue;
            }
            sz = sizes[group[i][j + 1]] + 1;
            if (group[i + 1][j] != group[i][j + 1]) sz += sizes[group[i + 1][j]];
            if (group[i][j - 1] != group[i][j + 1] && group[i][j - 1] != group[i + 1][j]) sz += sizes[group[i][j - 1]];
            if (group[i - 1][j] != group[i][j + 1] && group[i - 1][j] != group[i + 1][j] && group[i - 1][j] != group[i][j - 1]) sz += sizes[group[i - 1][j]];
            res[i - 1][j - 1] = sz % 10 + '0';
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}