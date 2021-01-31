#include <stdio.h>
#define INF 1234567890

int gal[256][2], mem[256][256][4];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, k, r;
    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) break;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= 3; k++) {
                    mem[i][j][k] = -INF;
                }
            }
        }
        mem[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &gal[i][0], &gal[i][1]);
            for (int j = 0; j <= i; j++) {
                mem[i][j][0] = big(big(mem[i - 1][j][0], mem[i - 1][j][1]), mem[i - 1][j][2]) + gal[i][0] + gal[i][1];
                mem[i][j][1] = (j > 0 ? big(mem[i - 1][j - 1][0], mem[i - 1][j - 1][1]) : -INF) + gal[i][0];
                mem[i][j][2] = (j > 0 ? big(mem[i - 1][j - 1][0], mem[i - 1][j - 1][2]) : -INF) + gal[i][1];
            }
        }
        r = big(big(mem[n][k][0], mem[n][k][1]), mem[n][k][2]);
        printf("%d\n", r);
    }
    return 0;
}