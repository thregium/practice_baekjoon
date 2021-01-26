#include <stdio.h>
#define DIV 1000000007

int mem[204800];
int f = 2;

int main(void) {
    int t, n;
    scanf("%d", &t);
    mem[1] = 1;
    mem[2] = 2;
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = f + 1; i <= n; i++) {
            mem[i] = (mem[i - 1] + mem[i - 2]) % DIV;
        }
        if (n > f) f = n;
        printf("%d\n", mem[n]);
    }
    return 0;
}