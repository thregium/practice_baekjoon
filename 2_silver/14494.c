#include <stdio.h>
#define DIV 1000000007

int mem[1024][1024];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    mem[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mem[i][j] = ((mem[i - 1][j] + mem[i - 1][j - 1]) % DIV + mem[i][j - 1]) % DIV;
        }
    }
    printf("%d", mem[n][m]);
    return 0;
}