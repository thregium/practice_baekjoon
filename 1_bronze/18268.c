#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int rank[16][32];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("gymnastics.in", "r");
        fo = fopen("gymnastics.out", "w");
    }
    int k, n, c, a = 0, b = 0, p, r = 0;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &rank[i][j]);
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = x + 1; y <= n; y++) {
            c = 1;
            p = 0;
            for (int z = 0; z < k; z++) {
                for (int w = 0; w < n; w++) {
                    if (rank[z][w] == x) a = w;
                    if (rank[z][w] == y) b = w;
                }
                if (p == 0) {
                    if (a > b) p = -1;
                    if (b > a) p = 1;
                }
                else if (p > 0 && a > b) c = 0;
                else if (p < 0 && b > a) c = 0;
            }
            if (c) r++;
        }
    }
    printf("%d", r);
    return 0;
}