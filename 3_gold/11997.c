#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int cows[1024][3], ncows[2048][2048], scows[2048][2048];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("balancing.in", "r");
        fo = fopen("balancing.out", "w");
    }
    int n, mx = 1, my = 1, x, y, m, r = 9999;
    int p[4] = { 0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }
    qsort(cows, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && cows[i][0] != cows[i - 1][0]) mx += 2;
        cows[i][2] = mx;
    }
    for (int i = 0; i < n; i++) cows[i][0] = cows[i][2];
    qsort(cows, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < n; i++) {
        if (i > 0 && cows[i][1] != cows[i - 1][1]) my += 2;
        cows[i][2] = my;
    }
    for (int i = 0; i < n; i++) cows[i][1] = cows[i][2];

    for (int i = 0; i < n; i++) ncows[cows[i][0]][cows[i][1]]++;
    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= my; j++) {
            scows[i][j] = scows[i][j - 1] + ncows[i][j];
        }
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= my; j++) {
            scows[i][j] = scows[i - 1][j] + scows[i][j];
        }
    }

    for (int i = 0; i < mx; i += 2) {
        for (int j = 0; j < my; j += 2) {
            p[0] = scows[i][j];
            p[1] = scows[mx][j] - scows[i][j];
            p[2] = scows[i][my] - scows[i][j];
            p[3] = n - scows[mx][j] - scows[i][my] + scows[i][j];
            m = 0;
            for (int k = 0; k < 4; k++) {
                if (p[k] > m) m = p[k];
            }
            if (m <= 130) {
                r = r;
            }
            if (m < r) {
                r = m;
            }
        }
    }
    printf("%d", r);
    return 0;
}