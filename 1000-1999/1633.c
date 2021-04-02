#include <stdio.h>

int mem[1024][16][16];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int a, b, n, t = 0;
    //scanf("%d", &n);
    while (scanf("%d %d", &a, &b) != EOF) {
        //scanf("%d %d", &a, &b);
        t++;
        for (int i = 0; i <= 15; i++) {
            for (int j = 0; j <= 15; j++) {
                mem[t][i][j] = big(big((i > 0 ? mem[t - 1][i - 1][j] + a : 0), (j > 0 ? mem[t - 1][i][j - 1] + b : 0)), mem[t - 1][i][j]);
            }
        }
    }
    printf("%d", mem[t][15][15]);
    return 0;
}