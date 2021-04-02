#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int q[128][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowqueue.in", "r");
        fo = fopen("cowqueue.out", "w");
    }
    int n, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &q[i][0], &q[i][1]);
    }
    qsort(q, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (q[i][0] > t) t = q[i][0];
        t += q[i][1];
    }
    printf("%d", t);
    return 0;
}