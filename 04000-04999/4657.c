#include <stdio.h>

/*
문제 : R * C(R, C <= 20) 크기의 이미지가 주어질 때, (X, Y)가 있는 형태의 둘레를 구한다.

해결 방법 : (X, Y)에서 플러드필을 통해 8방향으로 형태를 확인한다. 만약 상하좌우가 빈 칸인 경우 둘레에 1씩 더해나간다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : MidC 2001 G번
*/

char grid[32][32];
int r, c, vis[32][32];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int isvalid(int x, int y) {
    if (vis[x][y]) return 0;
    if (grid[x][y] != 'X') return -1;
    return 1;
}

int dfs(int x, int y) {
    int res = 0, val;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        val = isvalid(x + dxy[i][0], y + dxy[i][1]);
        if (val == 0) continue;
        else if (val < 0) res += (~i & 1);
        else res += dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return res;
}

int main(void) {
    int x, y;
    while (1) {
        scanf("%d %d %d %d", &r, &c, &x, &y);
        if (r == 0) break;
        for (int i = 1; i <= r; i++) {
            scanf("%s", &grid[i][1]);
        }
        printf("%d\n", dfs(x, y));
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                grid[i][j] = 0;
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}