#include <stdio.h>

/*
문제 : H * W(H, W <= 8) 크기의 판에 6가지 색상이 주어진다.
가장 왼쪽 위와 상하좌우로 연결된 같은 칸의 색상을 바꾸는 연산을 5회 이내로 반복하여 만들 수 있는
가장 큰 C번 색의 연결된 칸의 개수를 구한다.

해결 방법 : 5회동안 각 색상을 연결하는 모든 방법을 시도해본 다음,
그 중 C번 색의 연결된 칸의 개수가 가장 많은 것을 구하면 된다. 각 단계에서 판의 상태는
스택을 이용하여 저장한다. 연결된 같은 칸 여부는 플러드필을 통해 구할 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필, 구현, 브루트 포스

출처 : JDC 2011 C번
*/

int p[8][16][16], vis[16][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w, c, best;

int isvalid(int l, int x, int y, int e) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || p[l][x][y] != e) return 0;
    return 1;
}

int dfs(int l, int x, int y, int e) {
    vis[x][y] = 1;
    int r = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(l, x + dxy[i][0], y + dxy[i][1], e)) r += dfs(l, x + dxy[i][0], y + dxy[i][1], e);
    }
    return r;
}

void track(int lv) {
    if (lv == 5) {
        int r;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (p[lv][i][j] != c) continue;
                r = dfs(lv, i, j, c);
                if (r > best) best = r;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
        return;
    }
    for (int i = 1; i <= 6; i++) {
        dfs(lv, 0, 0, p[lv][0][0]);
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (vis[j][k]) p[lv + 1][j][k] = i;
                else p[lv + 1][j][k] = p[lv][j][k];
                vis[j][k] = 0;
            }
        }
        track(lv + 1);
    }
}

int main(void) {
    while (1) {
        scanf("%d %d %d", &h, &w, &c);
        if (h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &p[0][i][j]);
            }
        }
        best = 0;
        track(0);
        printf("%d\n", best);
    }
    return 0;
}