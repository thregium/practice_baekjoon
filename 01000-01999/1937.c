#include <stdio.h>
#include <stdlib.h>

int map[512][512], bamboo[262144][3], mem[512][512];
int dxy[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, b, mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
            bamboo[(i - 1) * n + (j - 1)][0] = i;
            bamboo[(i - 1) * n + (j - 1)][1] = j;
            bamboo[(i - 1) * n + (j - 1)][2] = map[i][j];
        }
    }
    qsort(bamboo, n * n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n * n; i++) {
        x = bamboo[i][0];
        y = bamboo[i][1];
        mem[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            if (map[x][y] < map[x + dxy[i][0]][y + dxy[i][1]] && mem[x][y] < mem[x + dxy[i][0]][y + dxy[i][1]] + 1) mem[x][y] = mem[x + dxy[i][0]][y + dxy[i][1]] + 1;
        }
        if (mem[x][y] > mx) mx = mem[x][y];
    }
    printf("%d", mx);
    return 0;
}