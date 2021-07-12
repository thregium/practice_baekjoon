#include <stdio.h>

/*
문제 : 5 * 5 크기의 격자에서 상하좌우로 인접한 7개의 칸을 선택해 4개 이상이 S가 되도록 하는 조합의 수를 구한다.

해결 방법 : 25개 중 7개의 칸을 조합을 통해 선택한 후 플러드필을 통해 모두 인접한지 확인한 후, 4개 이상이 S인지 확인하면 된다.

주요 알고리즘 : 브루트 포스, 플러드필
*/

int sel[8][8], vis[5][5];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char sy[8][8];
int res = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 5 || y >= 5) return 0;
    if (vis[x][y] || !sel[x][y]) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int check(void) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vis[i][j] = 0;
            if (sel[i][j] && sy[i][j] == 'S') cnt++;
        }
    }
    if (cnt < 4) return 0;
    cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!vis[i][j] && sel[i][j]) {
                dfs(i, j);
                cnt++;
                if (cnt > 1) return 0;
            }
        }
    }
    return 1;
}

void track(int c, int x, int y) {
    if (c == 7) {
        if (check()) res++;
        return;
    }

    for (int i = y + 1; i < 5; i++) {
        if (sel[x][i]) continue;
        sel[x][i] = 1;
        track(c + 1, x, i);
        sel[x][i] = 0;
    }
    for (int i = x + 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (sel[i][j]) continue;
            sel[i][j] = 1;
            track(c + 1, i, j);
            sel[i][j] = 0;
        }
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        scanf("%s", sy[i]);
    }
    track(0, 0, -1);
    printf("%d", res);
    return 0;
}