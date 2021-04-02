#include <stdio.h>

int mem[64];

int fibo(int n) {
    if (mem[n]) return mem[n];
    if (n <= 1) return mem[n] = 1;
    if (n == 2) return mem[n] = 2;
    return mem[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void) {
    int n, m, v, l = 0, r = 1;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v);
        r *= fibo(v - l - 1);
        l = v;
    }
    r *= fibo(n - l);
    printf("%d", r);
    return 0;
}