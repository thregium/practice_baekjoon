#include <stdio.h>

long long d10[24];

int available(long long n, long long k, int d) {
    char appear[10] = { 0, };
    for (int i = 0; i < d; i++) n /= 10;
    for (long long x = n; x; x /= 10) {
        appear[x % 10]++;
    }
    int r = 0;
    for (int i = 0; i < 10; i++) {
        r += !!appear[i];
    }
    if (r > k || r < k - d) return 0;
    return 1;
}

int main(void) {
    long long n, k, t, d, x;
    scanf("%lld %lld", &n, &k);
    t = n;
    x = 1;
    for (int i = 0; i <= 18; i++) {
        d10[i] = x;
        x *= 10;
    }
    d = 0;
    while (1) {
        if (available(t, k, d)) {
            d--;
            if (d < 0) break;
            else continue;
        }
        t += d10[d];
        if (t / d10[d] % 10 == 0) d++;
    }
    printf("%lld", t);
    return 0;
}