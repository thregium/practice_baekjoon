#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int x[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("angry.in", "r");
        fo = fopen("angry.out", "w");
    }
    int n, l, lt, r, rt, t, p, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        l = i;
        lt = i;
        r = i;
        rt = i;
        t = 1;
        p = 1;
        while (l > 0) {
            if (lt > 0 && x[l] <= x[lt - 1] + t) lt--;
            else if (lt < l) {
                p += l - lt;
                l = lt;
                t++;
            }
            else break;
        }
        t = 1;
        while (r + 1 < n) {
            if (rt + 1 < n && x[r] >= x[rt + 1] - t) rt++;
            else if (rt > r) {
                p += rt - r;
                r = rt;
                t++;
            }
            else break;
        }
        if (p > res) res = p;
    }
    printf("%d", res);
    return 0;
}