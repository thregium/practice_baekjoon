#include <stdio.h>

int candy[384][384], mem[384][384];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        candy[x][y] = m;
    }
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            mem[i][j] = big(i > 0 ? mem[i - 1][j] : 0, j > 0 ? mem[i][j - 1] : 0) + ((i + j) > candy[i][j] ? 0 : candy[i][j] - (i + j));
        }
    }
    printf("%d", mem[300][300]);
    return 0;
}