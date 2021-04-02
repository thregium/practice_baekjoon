#include <stdio.h>

long long a[1048576];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long small3(long long a, long long b, long long c) {
    return small(small(a, b), c);
}

int main(void) {
    int f = 0;
    long long s, n, b, c, r = 0;
    scanf("%lld %lld %lld", &n, &b, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (c < b) {
        for (int i = 0; i < n; i++) {
            if (i < n - 2 && a[i] && a[i + 1] && a[i + 2]) {
                if (f) {
                    s = small(a[i], a[i + 1]);
                    a[i] -= s;
                    a[i + 1] -= s;
                    r += s * (b + c);
                    f = 0;
                }
                else {
                    s = small3(a[i], a[i + 1], a[i + 2]);
                    if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) {
                        f = 1;
                        s -= small(small(a[i], a[i + 2]), small(a[i + 1] - a[i], a[i + 1] - a[i + 2]));
                    }
                    a[i] -= s;
                    a[i + 1] -= s;
                    a[i + 2] -= s;
                    r += s * (b + 2 * c);
                    i--;
                    continue;
                }
            }
            if (i < n - 1 && a[i] && a[i + 1]) {
                s = small(a[i], a[i + 1]);
                a[i] -= s;
                a[i + 1] -= s;
                r += s * (b + c);
                //printf("(i = %d) +5 * %d\n", i, s);
            }
            if (a[i]) {
                s = a[i];
                a[i] -= s;
                r += s * b;
                //printf("(i = %d) +3 * %d\n", i, s);
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            r += a[i] * b;
        }
    }
    printf("%lld", r);
    return 0;
}