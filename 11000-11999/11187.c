#include <stdio.h>
#include <stdlib.h>

int a[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, d, n, r = 0;
    scanf("%d %d %d", &l, &d, &n);
    if (n == 0) {
        if (l < 12) printf("0");
        else printf("%d", (l - 12) / d + 1);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    r += (a[0] - 6) / d;
    for (int i = 1; i < n; i++) {
        r += (a[i] - a[i - 1]) / d - 1;
    }
    r += (l - 6 - a[n - 1]) / d;
    printf("%d", r);
    return 0;
}