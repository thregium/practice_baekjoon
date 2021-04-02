#include <stdio.h>
#define INF 1234567890

int cards[2048][2], mem[2048][2048];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i][1]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            mem[i][j] = -INF;
        }
    }
    mem[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mem[i + 1][j + 1] = big(mem[i + 1][j + 1], mem[i][j]);
            mem[i + 1][j] = big(mem[i + 1][j], mem[i][j]);
            if (cards[i][0] > cards[j][1]) {
                mem[i][j + 1] = big(mem[i][j + 1], mem[i][j] + cards[j][1]);
            }
            //mem[i][j] = big(big(mem[i - 1][j], mem[i - 1][j - 1]), (cards[i][0] > cards[j][1] ? (mem[i][j - 1] + cards[j][1]) : -1));
        }
    }
    r = 0;
    for (int i = 0; i <= n; i++) {
        r = big(r, big(mem[i][n], mem[n][i]));
    }
    printf("%d", r);
    return 0;
}