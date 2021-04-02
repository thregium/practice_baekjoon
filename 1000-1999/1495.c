#include <stdio.h>

int v[128], mem[128][1024];

int main(void) {
    int n, s, m, x = -1;
    scanf("%d %d %d", &n, &s, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    mem[0][s] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (mem[i][j]) {
                if (j - v[i] >= 0) mem[i + 1][j - v[i]] = 1;
                if (j + v[i] <= m) mem[i + 1][j + v[i]] = 1;
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        if (mem[n][i]) x = i;
    }
    printf("%d", x);
    return 0;
}