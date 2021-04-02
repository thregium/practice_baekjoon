#include <stdio.h>
#include <stdlib.h>

int a[64], r[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, lar, sel;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        lar = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > lar) lar = a[j];
        }
        if (a[0] + 1 == lar) {
            sel = -1;
            for (int j = 1; j < n - i; j++) {
                if (a[j] == a[0] + 1) {
                    sel = j;
                    break;
                }
            }
            if (sel < 0) return 1;
            r[i] = a[sel];
            for (int j = sel; j < n - i - 1; j++) {
                a[j] = a[j + 1];
            }
        }
        else if (lar > a[0] + 1 && i > 0 && a[0] == r[i - 1] + 1) {
            sel = -1;
            for (int j = 1; j < n - i; j++) {
                if (a[j] > r[i - 1] + 1) {
                    sel = j;
                    break;
                }
            }
            if (sel < 0) return 1;
            r[i] = a[sel];
            for (int j = sel; j < n - i - 1; j++) {
                a[j] = a[j + 1];
            }
        }
        else {
            r[i] = a[0];
            for (int j = 0; j < n - i - 1; j++) {
                a[j] = a[j + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    return 0;
}