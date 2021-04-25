#include <stdio.h>

long long sum1(long long x) {
    int a = 0;
    long long r = 0;
    for (int i = 62; i >= 0; i--) {
        if (x & (1LL << i)) {
            r += i * (1LL << (i - 1)) + a * (1LL << i) + 1;
            a++;
        }
    }
    return r;
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", sum1(b) - sum1(a - 1));
    return 0;
}