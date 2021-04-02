#include <stdio.h>

int maze[1024][1024], mem[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &maze[i][j]);
            mem[i][j] = big(i > 0 ? mem[i - 1][j] : 0, j > 0 ? mem[i][j - 1] : 0) + maze[i][j];
        }
    }
    printf("%d", mem[n][m]);
    return 0;
}