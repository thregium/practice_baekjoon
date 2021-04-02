#include <stdio.h>

long long n;
long long d10[24];

int possible(int p, int d1, int c1, int d2, int c2) {
    long long x = n;
    int t1 = 0, t2 = 0;
    for (int i = 0; x; i++) {
        if (i >= p && x % 10 == d1) t1++;
        if (i >= p && x % 10 == d2) t2++;
        x /= 10;
    }
    t1 = c1 < t1 ? 0 : c1 - t1;
    t2 = c2 < t2 ? 0 : c2 - t2;
    return (t1 + t2 <= p);
}

int main(void) {
    int d1, c1, d2, c2, p = 0;
    scanf("%lld %d %d %d %d", &n, &d1, &c1, &d2, &c2);
    long long x = 1;
    for (int i = 0; i <= 16; i++) {
        d10[i] = x;
        x *= 10;
    }
    while (p >= 0) {
        if (possible(p, d1, c1, d2, c2)) p--;
        else {
            n += d10[p];
            if (n / d10[p] % 10 == 0) p++;
        }
    }
    printf("%lld", n);
    return 0;
}