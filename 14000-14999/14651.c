#include <stdio.h>
#define DIV 1000000009

long long mem[38400][3];

int main(void) {
    int n;
    scanf("%d", &n);
    mem[1][1] = 1;
    mem[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        mem[i][0] = (mem[i - 1][0] + mem[i - 1][1] + mem[i - 1][2]) % DIV;
        mem[i][1] = (mem[i - 1][0] + mem[i - 1][1] + mem[i - 1][2]) % DIV;
        mem[i][2] = (mem[i - 1][0] + mem[i - 1][1] + mem[i - 1][2]) % DIV;
    }
    printf("%lld", mem[n][0]);
    return 0;
}