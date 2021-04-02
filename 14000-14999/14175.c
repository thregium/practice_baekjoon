#include <stdio.h>
#define FOUT 0

char p[16][16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowsignal.in", "r");
        fo = fopen("cowsignal.out", "w");
    }
    int m, n, k;
    fscanf(fi, "%d %d %d", &m, &n, &k);
    for (int i = 0; i < m; i++) {
        fscanf(fi, "%s", p[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < k; jj++) {
                    fprintf(fo, "%c", p[i][ii]);
                }
            }
            fprintf(fo, "\n");
        }
    }
    return 0;
}