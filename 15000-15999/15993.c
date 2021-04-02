#include <stdio.h>
#define DIV 1000000009

int mem[102400][2];

int main(void) {
    int t, n;
    scanf("%d", &t);
    mem[0][0] = 1;
    for (int i = 1; i <= 100000; i++) {
        mem[i][0] = mem[i - 1][1];
        mem[i][1] = mem[i - 1][0];
        if (i > 1) {
            mem[i][0] = (mem[i][0] + mem[i - 2][1]) % DIV;
            mem[i][1] = (mem[i][1] + mem[i - 2][0]) % DIV;
        }
        if (i > 2) {
            mem[i][0] = (mem[i][0] + mem[i - 3][1]) % DIV;
            mem[i][1] = (mem[i][1] + mem[i - 3][0]) % DIV;
        }
    }

    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%d %d\n", mem[n][1], mem[n][0]);
    }
    return 0;
}