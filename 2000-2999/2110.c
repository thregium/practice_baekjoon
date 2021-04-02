#include <stdio.h>
#include <stdlib.h>

int x[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int possible(int a, int n, int c) {
    int last = x[0];
    int d = 1;
    for (int i = 1; i < n; i++) {
        if (x[i] - last >= a) {
            last = x[i];
            d++;
        }
    }
    if (d >= c) return 1;
    else return 0;
}

int main(void) {
    int n, c, h, l;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    h = (x[n - 1] - x[0]) / (c - 1);
    l = 1;
    while (h > l) {
        if (possible((h + l + 1) / 2, n, c)) l = (h + l + 1) / 2;
        else h = (h + l + 1) / 2 - 1;
    }
    printf("%d", h);
    return 0;
}