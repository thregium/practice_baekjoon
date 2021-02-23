#include <stdio.h>
#define DIV 1000000009

int mem[102400];

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    mem[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        mem[i] = mem[i - 1];
        if (i > 1) mem[i] = (mem[i] + mem[i - 2]) % DIV;
        if (i > 2) mem[i] = (mem[i] + mem[i - 3]) % DIV;
    }
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = mem[(n + 1) / 2 - 1];
        if (n % 2 == 0) {
            r = (r + mem[n / 2 - 1]) % DIV;
            if (n > 2) {
                r = (r + mem[n / 2 - 2]) % DIV;
            }
            if (n > 4) {
                r = (r + mem[n / 2 - 3]) % DIV;
            }
        }
        if (n > 2 && n % 2 != 0) {
            r = (r + mem[(n - 1) / 2 - 1]) % DIV;
        }
        printf("%d\n", r);
    }
    return 0;
}