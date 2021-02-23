#include <stdio.h>

int candy[5120][2], mem[5120][10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, c;
    double m, p;
    while (1) {
        scanf("%d %lf", &n, &m);
        if (n == 0 && m == 0.0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d %lf", &c, &p);
            candy[i][0] = c;
            candy[i][1] = p * 100 + 0.01;
        }
        c = m * 100 + 0.01;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= c; j++) {
                mem[i][j] = big(mem[i - 1][j], candy[i][1] > j ? 0 : mem[i][j - candy[i][1]] + candy[i][0]);
            }
        }

        printf("%d\n", mem[n][c]);
    }
    return 0;
}