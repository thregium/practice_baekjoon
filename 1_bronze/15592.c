#include <stdio.h>
#define IN fi
#define OUT fo

int bb[2048][2048];

int main(void) {
    int a, b, c, d, e, f, g, h, hs, he, vs, ve, mh = 0, mv = 0;
    FILE* fi = fopen("billboard.in", "r");
    FILE* fo = fopen("billboard.out", "w");
    fscanf(IN, "%d %d %d %d", &a, &b, &c, &d);
    fscanf(IN, "%d %d %d %d", &e, &f, &g, &h);
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            bb[i + 1000][j + 1000] = 1;
        }
    }
    for (int i = e; i < g; i++) {
        for (int j = f; j < h; j++) {
            bb[i + 1000][j + 1000] = 0;
        }
    }
    for (int i = 0; i <= 2000; i++) {
        hs = -1;
        he = -2;
        vs = -1;
        ve = -2;
        for (int j = 0; j <= 2000; j++) {
            if (bb[i][j] && hs < 0) hs = j;
            if (bb[i][j]) he = j;
            if (bb[j][i] && vs < 0) vs = j;
            if (bb[j][i]) ve = j;
        }
        if (he - hs + 1 > mh) mh = he - hs + 1;
        if (ve - vs + 1 > mv) mv = ve - vs + 1;
    }
    fprintf(OUT, "%d", mh * mv);
    return 0;
}