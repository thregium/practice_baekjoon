#include <stdio.h>
#define MAXI 1234567890

int mem[1280][24];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int e[24], s[24];
    int c, n, l = MAXI;
    scanf("%d %d", &c, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &e[i], &s[i]);
    }
    for (int i = 0; i <= 1279; i++) {
        for (int j = 0; j <= n; j++) mem[i][j] = MAXI;
    }

    mem[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1279; j++) {
            mem[j][i] = small(mem[j][i - 1], s[i] > j ? MAXI : mem[j - s[i]][i] + e[i]);
            if (j >= c && mem[j][i] < l) l = mem[j][i];
        }
    }

    printf("%d\n", l);
    return 0;
}