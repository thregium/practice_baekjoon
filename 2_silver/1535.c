#include <stdio.h>

int h[24], e[24];
int mem[128][24];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &e[i]);

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 100; i++) {
            mem[i][j] = big(mem[i][j - 1], h[j] > i ? 0 : mem[i - h[j]][j - 1] + e[j]);
        }
    }
    printf("%d", mem[99][n]);
    return 0;
}