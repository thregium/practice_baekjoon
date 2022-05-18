#include <stdio.h>

int main(void) {
    int t, o, stt;
    unsigned long long n, p, q;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%llu", &n);
            p = 1, q = 1, stt = 0;
            for (int i = 63; i >= 0; i--) {
                if (!stt) {
                    if ((n >> i) & 1) stt = 1;
                    continue;
                }
                if ((n >> i) & 1) p += q;
                else q += p;
            }
            printf("Case #%d: %llu %llu\n", tt, p, q);
        }
        else {
            scanf("%llu %llu", &p, &q);
            n = 0;
            for (int i = 0; i < 64; i++) {
                if (p > q) {
                    n += (1ULL << i);
                    p -= q;
                }
                else if (p < q) q -= p;
                else {
                    n += (1ULL << i);
                    break;
                }
            }
            printf("Case #%d: %llu\n", tt, n);
        }
    }
    return 0;
}