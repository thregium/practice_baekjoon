#include <stdio.h>
#include <stdlib.h>
#define INF 1023456789
#define FOUT 0
/*
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
*/

int cows[64][3], cross[4096][3], rut[64];
int cp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("f.in", "r");
        fo = fopen("f.out", "w");
    }
    int n, xd, yd;
    char d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("\n%c %d %d", &d, &cows[i][1], &cows[i][2]);
        if (d == 'N') cows[i][0] = 0;
        else if (d == 'E') cows[i][0] = 1;
        else if (d == 'S') cows[i][0] = 2;
        else if (d == 'W') cows[i][0] = 3;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (cows[i][0] == cows[j][0]) continue;
            xd = cows[i][1] - cows[j][1];
            yd = cows[i][2] - cows[j][2];
            if (cows[j][0] == 0 && yd < 0) continue;
            if (cows[j][0] == 1 && xd < 0) continue;

            if (cows[i][0] == 0) {
                if (yd > 0 || abs(yd) - abs(xd) <= 0) continue;
                cross[cp][0] = -yd;
            }
            if (cows[i][0] == 1) {
                if (xd > 0 || abs(xd) - abs(yd) <= 0) continue;
                cross[cp][0] = -xd;
            }
            cross[cp][1] = i;
            cross[cp][2] = j;
            cp++;
        }
    }

    qsort(cross, cp, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        rut[i] = INF;
    }
    for (int i = 0; i < cp; i++) {
        if (rut[cross[i][1]] > cross[i][0]) {
            if (cows[cross[i][2]][0] == 0 && cows[cross[i][2]][2] + rut[cross[i][2]] < cows[cross[i][1]][2]) continue;
            if (cows[cross[i][2]][0] == 1 && cows[cross[i][2]][1] + rut[cross[i][2]] < cows[cross[i][1]][1]) continue;
            rut[cross[i][1]] = cross[i][0];
        }
    }
    for (int i = 0; i < n; i++) {
        if (rut[i] == INF) printf("Infinity\n");
        else printf("%d\n", rut[i]);
    }
    return 0;
}