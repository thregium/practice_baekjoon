#include <stdio.h>

int area[384][384], mem[384][384];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &area[i][j]);
            mem[i][j] = big(mem[i - 1][j], mem[i][j - 1]) + area[i][j];
        }
    }
    printf("%d", mem[n][m]);
    return 0;
}