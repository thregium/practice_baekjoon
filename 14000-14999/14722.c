#include <stdio.h>

int milk[1024][1024], mem[3][1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &milk[i][j]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            mem[0][i][j] = -3;
            mem[1][i][j] = -2;
            //mem[2][i][j] = -1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mem[0][i][j] = big(milk[i][j] == 0 ? big(mem[2][i - 1][j], mem[2][i][j - 1]) + 1 : -3, big(mem[0][i - 1][j], mem[0][i][j - 1]));
            mem[1][i][j] = big(milk[i][j] == 1 ? big(mem[0][i - 1][j], mem[0][i][j - 1]) + 1 : -2, big(mem[1][i - 1][j], mem[1][i][j - 1]));
            mem[2][i][j] = big(milk[i][j] == 2 ? big(mem[1][i - 1][j], mem[1][i][j - 1]) + 1 : -1, big(mem[2][i - 1][j], mem[2][i][j - 1]));
        }
    }
    r = big(big(mem[0][n][n], mem[1][n][n]), mem[2][n][n]);
    printf("%d", r);
    return 0;
}