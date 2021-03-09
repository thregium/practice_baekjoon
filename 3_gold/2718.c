#include <stdio.h>
#define DIV 2147483647

int blocks[256][32768]; //i : m번째 칸, j : 각 행의 블록 여부

int main(void) {
    int t, nt, n = 4, m = 21;
    blocks[0][0] = 1;
    for (int i = 1; i <= n * m; i++) {
        for (int j = 0; j < 1 << n; j++) {
            if ((j >> (n - 1)) % 2 == 0) {
                blocks[i][j] = (blocks[i][j] + blocks[i - 1][(j << 1) + 1]) % DIV;
            }
            if ((j >> (n - 1)) % 2 == 1) {
                blocks[i][j] = (blocks[i][j] + blocks[i - 1][(j << 1) % (1 << n)]) % DIV;
            }
            if ((i - 1) % n > 0 && (j >> (n - 2)) % 4 == 0) {
                blocks[i][j] = (blocks[i][j] + blocks[i - 2][j << 2]) % DIV;
            }
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &nt);
        printf("%d\n", blocks[nt * n][0]);
    }
    return 0;
}