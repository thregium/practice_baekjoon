#include <stdio.h>

int mem[24][10240];

int main(void) {
    int t, n, m;
    int c[24];
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        scanf("%d", &m);

        mem[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                mem[i][j] = mem[i - 1][j] + (c[i] > j ? 0 : mem[i][j - c[i]]);
            }
        }
        printf("%d\n", mem[n][m]);
    }
    return 0;
}