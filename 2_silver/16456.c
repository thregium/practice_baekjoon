#include <stdio.h>
#define DIV 1000000009

int mem[51200][2]; //0 : 1ĭ, 1 : 2, 2 : 2->-1, 3 : 2->-1->2

int main(void) {
    int n;
    scanf("%d", &n);
    mem[1][0] = 1;
    mem[2][0] = 1;
    for (int i = 3; i <= n; i++) {
        mem[i][0] = (mem[i - 1][0] + mem[i - 1][1]) % DIV;
        mem[i][1] = (mem[i - 3][0] + mem[i - 3][1]) % DIV;
    }
    printf("%d", ((mem[n][0] + mem[n][1]) % DIV + (mem[n - 2][0] + mem[n - 2][1]) % DIV) % DIV);
    return 0;
}