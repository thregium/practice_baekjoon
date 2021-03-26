#include <stdio.h>

long long c[64][64], p[64];
int k[64] = { -1, 1, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 3, 2, 3, 3, 4, 3, 4, 4, 3, 3, 4, 4, 3, 4, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 3, 3, 4, 4, 3, 4, 3, 3, 4, 3, 4, 4, 3, 4, 3, 3, 4, 4, 3, 3, 4, 3, 4, 4 };

long long sumk(long long x, int y) {
    int a = 0;
    long long r = 0;
    for (int i = 62; i >= 0; i--) {
        if (x & (1LL << i)) {
            for (int j = 0; j <= i; j++) {
                p[j + a] += c[i][j];
            }
            a++;
        }
    }
    a = a;
    for (int i = 0; i < 64; i++) {
        if (k[i] == y) r += p[i];
        p[i] = 0;
    }
    if (x > 1 && y == 0) r++;
    if (x > 1 && y == 1) r--;
    return r;
}

int main(void) {
    int x, cnt = 0;
    long long lo, hi;
    c[0][0] = 1;
    for (int i = 1; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            c[i][j] = c[i - 1][j];
            if (j > 0) c[i][j] += c[i - 1][j - 1];
        }
    }
    while (1) {
        scanf("%lld %lld %d", &lo, &hi, &x);
        if (!lo && !hi && !x) break;
        cnt++;
        if (cnt > 10000) return 1;
        printf("%lld\n", sumk(hi + 1, x) - sumk(lo, x));
    }
    return 0;
}