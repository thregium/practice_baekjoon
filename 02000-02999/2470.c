#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 1012345678

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l = 0, h, bl = INF, bh = INF;
    scanf("%d", &n);
    h = n - 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = h; j > i ; j--) {
            if (abs(a[i] + a[j]) < abs(bl + bh)) {
                bl = a[i];
                bh = a[j];
            }
            if (a[i] + a[j] > 0) h--;
            if (a[i] + a[j] < 0) break;
        }
    }
    printf("%d %d", bl, bh);
    return 0;
}