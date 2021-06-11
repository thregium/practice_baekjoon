#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int fibo[103000], a[103000], rng[204800][2], st[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, q;
    scanf("%d%d", &n, &q);
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= 102400; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &rng[i * 2][0], &rng[i * 2 + 1][0]);
        rng[i * 2][1] = -i - 1;
        rng[i * 2 + 1][1] = 1 + i;
    }
    qsort(rng, q * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < q * 2; i++) {
        if (rng[i][1] < 0) {
            a[rng[i][0]]++;
            st[-rng[i][1]] = rng[i][0];
        }
        else {
            a[rng[i][0]]++;
        }
    }
    return 0;
}