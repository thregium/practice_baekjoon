#include <stdio.h>

/*
문제 : H * W(H, W <= 50) 크기의 격자에 'B', 'W', '.'이 적혀있다. 어떤 '.'에서 상하좌우로 움직였을 때
'B' 또는 'W' 중 한 가지만 만날 수 있다면 그 색으로 둘러싸였다고 한다. 'B'와 'W'로 둘러싸인 칸의 개수를
각각 구한다.

해결 방법 : 각 '.'에서 플러드필을 통해 주위에 'B'와 'W'가 있는 지 여부를 확인한다.
둘 중 하나만 있다면 다시 플러드필을 하여 '.'의 개수를 세고 그 색에 둘러싸인 칸의 개수에 해당 '.' 묶음의 개수를 추가한다.
이를 모든 칸에 대해 반복하고 각 색에 둘러싸인 칸의 개수를 구하면 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : JAG 2007D C번
*/

char ground[64][64], vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int w, h;

int isvalid(int x, int y, int p) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] != p) return 0;
    if (ground[x][y] == 'B') return -1;
    if (ground[x][y] == 'W') return -2;
    return 1;
}

int dfs1(int x, int y) {
    vis[x][y] = 1;
    int r = 0, t;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x + dxy[i][0], y + dxy[i][1], 0);
        if (t < 0) r |= (-t);
        else if (t > 0) r |= dfs1(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int dfs2(int x, int y) {
    vis[x][y] = 2;
    int r = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], 1)) r += dfs2(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int black, white, t;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        black = 0, white = 0;
        for (int i = 0; i < h; i++) {
            scanf("%s", ground[i]);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!vis[i][j] && ground[i][j] == '.') {
                    t = dfs1(i, j);
                    if (t == 1) {
                        black += dfs2(i, j);
                    }
                    else if (t == 2) {
                        white += dfs2(i, j);
                    }
                }
            }
        }

        printf("%d %d\n", black, white);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
    }
    return 0;
}