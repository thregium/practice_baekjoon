#include <stdio.h>
#include <stdlib.h>

int a[4096][4], fs[16777216], tf[16777216];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l = -2147483647, m = 0, p, t;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fs[i * n + j] = a[i][0] + a[j][1];
            tf[i * n + j] = a[i][2] + a[j][3];
        }
    }
    qsort(fs, n * n, sizeof(int), cmp1);
    qsort(tf, n * n, sizeof(int), cmp1);
    p = n * n - 1;
    for (int i = 0; i < n * n; i++) {
        if (fs[i] == l) r += m;
        else {
            t = 0;
            for (int j = p; j >= 0; j--) {
                if (fs[i] + tf[j] > 0) p--;
                if (fs[i] + tf[j] < 0) {
                    t = p - j;
                    break;
                }
                if (j == 0) t = p - j + 1;
            }
            r += t;
            l = fs[i];
            m = t;
        }
    }
    printf("%lld", r);
    return 0;
}