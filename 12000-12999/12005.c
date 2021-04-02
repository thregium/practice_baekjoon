#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int d[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("diamond.in", "r");
        fo = fopen("diamond.out", "w");
    }
    int n, k, j, best = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    qsort(d, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (d[j] - d[i] > k) break;
        }
        if (j - i > best) best = j - i;
    }
    printf("%d", best);
    return 0;
}