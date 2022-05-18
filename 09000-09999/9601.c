#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 50)개의 좌표축에 평행한 직사각형이 좌표평면상에 주어진다. 이때, 이 직사각형들로
나누어지는 구역의 개수를 구한다. 좌표의 범위는 절댓값 10^6 이하의 정수이다.

해결 방법 : 좌표 압축을 한 후 이를 지도에 그리고 플러드필을 통해 구역의 개수를 구하면 된다.
지도에 그리기 위해서는 좌표를 2배로 압축해야 한다.

주요 알고리즘 : 그래프 이론, 플러드필, 좌표 압축

출처 : Aizu 2013 C번
*/

int fence[64][4], xpos[128][3], ypos[128][3];
int map[256][256], vis[256][256];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int xsz, ysz;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x > xsz + 1 || y > ysz + 1) return 0;
    if (vis[x][y] || map[x][y] == 1) return 0;
    return 1;
}

int dfs(int x, int y) {
    int r = (map[x][y] == 2);
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) r += dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crazy.in", "r");
        fo = fopen("crazy.out", "w");
    }
    int n, c, r = 0, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &fence[i][0], &fence[i][1], &fence[i][2], &fence[i][3]);
            xpos[i][0] = fence[i][0];
            xpos[i][1] = i;
            ypos[i][0] = fence[i][1];
            ypos[i][1] = i;
            xpos[n + i][0] = fence[i][2];
            xpos[n + i][1] = n + i;
            ypos[n + i][0] = fence[i][3];
            ypos[n + i][1] = n + i;
        }

        qsort(xpos, n * 2, sizeof(int) * 3, cmp1);
        qsort(ypos, n * 2, sizeof(int) * 3, cmp1);

        xpos[0][2] = 1, ypos[0][2] = 1;
        for (int i = 1; i < n * 2; i++) {
            if (xpos[i][0] == xpos[i - 1][0]) xpos[i][2] = xpos[i - 1][2];
            else xpos[i][2] = xpos[i - 1][2] + 2;
            if (ypos[i][0] == ypos[i - 1][0]) ypos[i][2] = ypos[i - 1][2];
            else ypos[i][2] = ypos[i - 1][2] + 2;
        }
        for (int i = 0; i < n * 2; i++) {
            if (xpos[i][1] < n) fence[xpos[i][1]][0] = xpos[i][2];
            else if (xpos[i][1] < n * 2) fence[xpos[i][1] - n][2] = xpos[i][2];
            if (ypos[i][1] < n) fence[ypos[i][1]][1] = ypos[i][2];
            else if (ypos[i][1] < n * 2) fence[ypos[i][1] - n][3] = ypos[i][2];
        }

        for (int i = 0; i < n; i++) {
            if (fence[i][0] > fence[i][2]) swap(&fence[i][0], &fence[i][2]);
            if (fence[i][1] > fence[i][3]) swap(&fence[i][1], &fence[i][3]);

            for (int x = fence[i][0]; x <= fence[i][2]; x++) {
                for (int y = fence[i][1]; y <= fence[i][3]; y++) {
                    if (x == fence[i][0] || x == fence[i][2] || y == fence[i][1] || y == fence[i][3]) {
                        map[x][y] = 1;
                    }
                }
            }
        }

        xsz = xpos[n * 2 - 1][2];
        ysz = ypos[n * 2 - 1][2];
        r = 0;
        for (int i = 0; i <= xsz + 1; i++) {
            for (int j = 0; j <= ysz + 1; j++) {
                if (!vis[i][j] && map[i][j] != 1) {
                    t = dfs(i, j);
                    r++;
                }
            }
        }
        printf("%d\n", r);
        for (int i = 0; i <= xsz + 1; i++) {
            for (int j = 0; j <= ysz + 1; j++) {
                vis[i][j] = 0;
                map[i][j] = 0;
            }
        }
    }
    return 0;
}