#include <stdio.h>

int sieve[32768], primes[4096];
int pp = 0, ct = 0;

void track(int n, int r, int x, int l, int m, int y) {
    if (n == r) {
        if (n & 1) ct -= y / x;
        else ct += y / x;
        return;
    }
    for (int i = l + 1; i < m; i++) {
        if ((long long)x * primes[i] > y) break;
        track(n, r + 1, x * primes[i], i, m, y);
    }
}

int count(int x, int p) {
    int m = 0;
    for (int i = 0; i < pp; i++) {
        if (primes[i] == p) {
            m = i;
            break;
        }
    }
    ct = 0;
    for (int i = 0; i <= 20; i++) {
        track(i, 0, p, -1, m, x);
    }
    return ct;
}

int main(void) {
    int n, p;
    for (int i = 2; i < 32768; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j < 32768; j += i) {
            sieve[j] = 1;
        }
    }
    scanf("%d %d", &n, &p);
    int lo = 0, hi = 1000000000;
    while (hi > lo) {
        if (count((hi + lo) / 2, p) >= n) hi = (hi + lo) / 2;
        else lo = (hi + lo) / 2 + 1;
    }
    if (lo == 1000000000 && count(lo, p) < n) printf("0");
    else printf("%d", lo);
    return 0;
}