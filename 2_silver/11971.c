#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int road[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("speeding.in", "r");
        fo = fopen("speeding.out", "w");
    }
    int n, m, l, s, p = 0, x = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &s);
        for (int j = p; j < p + l; j++) {
            road[j] = s;
        }
        p += l;
    }
    p = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l, &s);
        for (int j = p; j < p + l; j++) {
            if (s - road[j] > x) x = s - road[j];
        }
        p += l;
    }
    printf("%d", x);
    return 0;
}