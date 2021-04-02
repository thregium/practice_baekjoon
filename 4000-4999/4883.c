#include <stdio.h>
#define INF 1234567890

int g[102400][3], m[102400][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    for (int t = 1; 1; t++) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d %d %d", &g[1][0], &g[1][1], &g[1][2]);
        m[1][0] = INF;
        m[1][1] = g[1][1];
        m[1][2] = m[1][1] + g[1][2];
        for (int i = 2; i <= n; i++) {
            scanf("%d %d %d", &g[i][0], &g[i][1], &g[i][2]);
            m[i][0] = small(m[i - 1][0], m[i - 1][1]) + g[i][0];
            m[i][1] = small(small(m[i - 1][0], m[i - 1][1]), small(m[i - 1][2], m[i][0])) + g[i][1];
            m[i][2] = small(small(m[i - 1][1], m[i - 1][2]), m[i][1]) + g[i][2];
        }
        printf("%d. %d\n", t, m[n][1]);
    }
    return 0;
}