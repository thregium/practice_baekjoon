#include <stdio.h>
#define DIV 1000000009

int mem[1024][1024];
int f1 = 0, f2 = 0;

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    mem[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            mem[i][j] = mem[i - 1][j - 1];
            if (j > 1) mem[i][j] = (mem[i][j] + mem[i - 1][j - 2]) % DIV;
            if (j > 2) mem[i][j] = (mem[i][j] + mem[i - 1][j - 3]) % DIV;
        }
    }
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        r = 0;
        for (int i = 1; i <= m; i++) {
            r = (r + mem[i][n]) % DIV;
        }
        printf("%d\n", r);
    }
    return 0;
}