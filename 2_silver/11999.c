#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("pails.in", "r");
        fo = fopen("pails.out", "w");
    }
    int x, y, m, best = 0;
    scanf("%d %d %d", &x, &y, &m);
    for (int i = 0; i < m / x; i++) {
        if (best < m - (m - i * x) % y) best = m - (m - i * x) % y;
    }
    for (int i = 0; i < m / y; i++) {
        if (best < m - (m - i * y) % x) best = m - (m - i * y) % x;
    }
    printf("%d", best);
    return 0;
}