#include <stdio.h>
#define DIV 1000000007

int mem[1536][3];

int main(void) {
    int n;
    scanf("%d", &n);
    mem[1][1] = 1;
    mem[1][2] = 1;
    for (int i = 2; i < n; i++) {
        mem[i][0] = (mem[i - 1][1] + mem[i - 1][2]) % DIV;
        mem[i][1] = (mem[i - 1][0] + mem[i - 1][2]) % DIV;
        mem[i][2] = (mem[i - 1][0] + mem[i - 1][1]) % DIV;
    }
    printf("%d", mem[n - 1][1]);
    return 0;
}