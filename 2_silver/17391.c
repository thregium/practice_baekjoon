#include <stdio.h>
#define INF 1234567890

int boost[384][384], mem[384][384];

int small2(int a, int b) {
    if (a == 0) a = INF;
    if (b == 0) b = INF;
    return a < b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    mem[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &boost[i][j]);
            for (int k = 1; k <= boost[i][j]; k++) {
                if (i + k < n) mem[i + k][j] = small2(mem[i + k][j], mem[i][j] + 1);
                if (j + k < m) mem[i][j + k] = small2(mem[i][j + k], mem[i][j] + 1);
            }
        }
    }
    printf("%d", mem[n - 1][m - 1]);
    return 0;
}