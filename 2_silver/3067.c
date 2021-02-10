#include <stdio.h>

int mem[10240][24];

int main(void) {
    int c[32];
    int t, n, m, r;
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
                mem[j][i] = (j - c[i] >= 0 ? mem[j - c[i]][i] : 0) + mem[j][i - 1];
            }
        }

        printf("%d\n", mem[m][n]);
    }
    return 0;
}