#include <stdio.h>
#define DIV 1000000007

char sieve[4194304];
int primes[320000], cnt[320000];
int pp;

int main(void) {
    int n, k;
    long long r = 1;
    for (int i = 2; i <= 4000000; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j <= 4000000; j += i) {
            sieve[j] = 1;
        }
    }
    scanf("%d %d", &n, &k);
    for (int i = 0; i < pp; i++) {
        for (long long j = primes[i]; j <= n; j *= primes[i]) {
            cnt[i] += n / j;
            cnt[i] -= k / j;
            cnt[i] -= (n - k) / j;
        }
    }
    for (int i = 0; i < pp; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            r *= primes[i];
            r %= DIV;
        }
    }
    printf("%lld", r);
    return 0;
}