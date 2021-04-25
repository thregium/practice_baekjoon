#include <stdio.h>
#define DIV 1234567

int pw[1024][11];
int f = 1;

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i <= 9; i++) {
        pw[1][i] = 1;
    }
    pw[1][10] = 10;
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);

        for (int i = f + 1; i <= n; i++) {
            pw[i][0] = (pw[i - 1][7]) % DIV;
            pw[i][1] = (pw[i - 1][2] + pw[i - 1][4]) % DIV;
            pw[i][2] = (pw[i - 1][1] + pw[i - 1][3] + pw[i - 1][5]) % DIV;
            pw[i][3] = (pw[i - 1][2] + pw[i - 1][6]) % DIV;
            pw[i][4] = (pw[i - 1][1] + pw[i - 1][5] + pw[i - 1][7]) % DIV;
            pw[i][5] = (pw[i - 1][2] + pw[i - 1][4] + pw[i - 1][6] + pw[i - 1][8]) % DIV;
            pw[i][6] = (pw[i - 1][3] + pw[i - 1][5] + pw[i - 1][9]) % DIV;
            pw[i][7] = (pw[i - 1][0] + pw[i - 1][4] + pw[i - 1][8]) % DIV;
            pw[i][8] = (pw[i - 1][5] + pw[i - 1][7] + pw[i - 1][9]) % DIV;
            pw[i][9] = (pw[i - 1][6] + pw[i - 1][8]) % DIV;
            for (int j = 0; j < 10; j++) {
                pw[i][10] += pw[i][j];
            }
            pw[i][10] %= DIV;
        }
        if (n > f) f = n;

        printf("%d\n", pw[n][10]);
    }
    return 0;
}