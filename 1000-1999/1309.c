#include <stdio.h>
#define DIV 9901

int mem[102400][4];

int main(void) {
    int n;
    scanf("%d", &n);
    mem[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        mem[i][0] = (mem[i - 1][0] + mem[i - 1][1] + mem[i - 1][2]) % DIV;
        mem[i][1] = (mem[i - 1][0] + mem[i - 1][2]) % DIV;
        mem[i][2] = (mem[i - 1][0] + mem[i - 1][1]) % DIV;
    }
    printf("%d", (mem[n][0] + mem[n][1] + mem[n][2]) % DIV);
    return 0;
}