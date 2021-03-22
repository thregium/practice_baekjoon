#include <stdio.h>

int f[24][204800];

int main(void) {
    int m, q, n, x;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &f[0][i]);
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    scanf("%d", &q);
    for (int qq = 1; qq <= q; qq++) {
        scanf("%d %d", &n, &x);
        for (int i = 20; i >= 0; i--) {
            if (n & (1 << i)) {
                x = f[i][x];
            }
        }
        printf("%d\n", x);
    }
    return 0;
}