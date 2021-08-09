#include <stdio.h>

long long fibo[128], len[128], clen[128], cnt[128], cnts[128];

int main(void) {
    long long n, h = -1, r = 0, prior;
    fibo[1] = 1, fibo[2] = 1;
    len[1] = 1, len[2] = 2;
    clen[1] = 1, clen[2] = 3;
    cnt[1] = 1, cnt[2] = 1;
    cnts[1] = 1, cnts[2] = 2;
    for (int i = 3; i <= 75; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        len[i] = fibo[i] * i;
        clen[i] = clen[i - 1] + len[i];
        cnt[i] = fibo[i] + cnts[i - 2];
        cnts[i] = cnts[i - 1] + cnt[i];
    }
    scanf("%lld", &n);
    for (int i = 75; i >= 0; i--) {
        if (clen[i] < n) {
            h = i + 1;
            break;
        }
    }
    if (h < 0) return 1;
    r += cnts[h - 1];
    n -= clen[h - 1];
    prior = n / h;
    printf("%lld %lld", h, prior);
    return 0;
}