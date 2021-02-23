#include <stdio.h>

int mem[4][10240];

int main(void) {
    int t, n, f = -1;
    scanf("%d", &t);
    mem[0][0] = 1;
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= 3; i++) {
            for (int j = f + 1; j <= n; j++) {
                mem[i][j] = mem[i - 1][j] + (i > j ? 0 : mem[i][j - i]);
            }
        }
        if(n > f) f = n;
        printf("%d\n", mem[3][n]);
    }
    return 0;
}