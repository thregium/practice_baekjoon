#include <stdio.h>
#define DIV 100999

int mem[2048][2048], c[2048];

int main(void) {
    int t, n;

    mem[0][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        //mem[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            //mem[i][j] = mem[i][j - 1];
            for (int k = 0; k < j; k++) {
                mem[i][j] = (mem[i][j] + mem[i - j][k]) % DIV;
            }
            c[i] = (c[i] + mem[i][j]) % DIV;
        }
    }

    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%d\n", c[n]);
    }
    return 0;
}