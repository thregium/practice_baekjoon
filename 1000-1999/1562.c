#include <stdio.h>
#define DIV 1000000000

int mem[55][10][128];

int main(void) {
    int n, p, r = 0;
    scanf("%d", &n);
    for (int i = 1; i < 10; i++) {
        mem[55 - (10 - i) * (10 - i + 1) / 2][i][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j1 = 0; j1 < 10; j1++) {
            for (int j2 = j1; j2 < 10; j2++) {
                for (int k = 0; k < 10; k++) {
                    p = 55 - (10 - j1) * (11 - j1) / 2 + j2 - j1;
                    if (p == 11 && k == 1 && i == 3) {
                        i = i;
                    }
                    if (k < j1 || k > j2) continue;

                    if (k == j2 && j1 != j2) {
                        //mem[p + 1][k][i] = (mem[p + 1][k][i] + mem[p][k - 1][i - 1]) % DIV;
                        mem[p][k][i] = (mem[p][k][i] + mem[p - 1][k - 1][i - 1]) % DIV;
                    }
                    else if (k == j1 && j1 != j2) {
                        //mem[55 - (11 - j1) * (12 - j1) / 2 + j2 - j1 + 1][k][i] = (mem[55 - (11 - j1) * (12 - j1) / 2 + j2 - j1 + 1][k][i] + mem[p][k + 1][i - 1]) % DIV;
                        mem[p][k][i] = (mem[p][k][i] + mem[55 - (9 - j1) * (10 - j1) / 2 + j2 - j1 - 1][k + 1][i - 1]) % DIV;
                    }
                    
                    mem[p][k][i] = (mem[p][k][i] + ((k > 0 ? mem[p][k - 1][i - 1] : 0) + (k < 9 ? mem[p][k + 1][i - 1] : 0)) % DIV) % DIV;
                    
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        //for (int j = 1; j <= 40; j++) {
            r = (r + mem[9][i][n]) % DIV;
        //}
    }
    printf("%d", r);
    return 0;
}