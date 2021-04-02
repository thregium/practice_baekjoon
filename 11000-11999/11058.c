#include <stdio.h>

long long mem[128];

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    long long b;
    scanf("%d", &n);

    mem[0] = 0;
    for (int i = 1; i <= n; i++) {
        b = 0;
        if (i > 0) b = max(b, mem[i - 1] + 1);
        if (i > 1) {
            for (int j = i - 2; j >= 0; j--) {
                b = max(b, mem[j] * (i - j - 1));
            }
        }
        mem[i] = b;
    }
    printf("%lld", mem[n]);
    return 0;
}