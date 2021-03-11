#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int milk[64][64], sick[64], ps[64];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("badmilk.in", "r");
        fo = fopen("badmilk.out", "w");
    }
    int n, m, d, s, p, mi, t, x, r = 0;
    scanf("%d %d %d %d", &n, &m, &d, &s);
    for (int i = 0; i < n; i++) {
        sick[i] = -1;
        for (int j = 0; j < m; j++) {
            milk[i][j] = 9999;
        }
    }

    for (int i = 0; i < d; i++) {
        scanf("%d %d %d", &p, &mi, &t);
        if(milk[p - 1][mi - 1] > t) milk[p - 1][mi - 1] = t;
    }
    for (int i = 0; i < s; i++) {
        scanf("%d %d", &p, &t);
        sick[p - 1] = t;
    }

    for (int i = 0; i < m; i++) {
        x = 1;
        for (int j = 0; j < n; j++) {
            if (sick[j] >= 0 && milk[j][i] >= sick[j]) {
                x = 0;
                break;
            }
        }
        if (!x) continue;
        for (int j = 0; j < n; j++) {
            if (milk[j][i] < 9999) ps[j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        r += ps[i];
    }
    printf("%d", r);
    return 0;
}