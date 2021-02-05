#include <stdio.h>
#define INF 1234567890

char r[16][16];
int mem[16][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int available(int now, int prev, int x, int n) {
    for (int i = 0; i < n; i++) {
        if ((now >> i) % 2 && r[i][x - 1] == 'x') return 0;
        if (((now >> i) % 2 || (now >> i + 1) % 2) && ((prev >> i) % 2 || (prev >> i + 1) % 2)) return 0;
    }
    return 1;
}

int students(int line) {
    int res = 0;
    while (line) {
        if (line % 2) res++;
        line >>= 1;
    }
    return res;
}

int main(void) {
    int c, n, m, a, s;
    scanf("%d", &c);
    for (int tt = 0; tt < c; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", r[i]);
        }

        mem[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                for (int k = 0; k < (1 << n); k++) {
                    if (available(j, k, i, n)) {
                        mem[i][j] = big(mem[i][j], mem[i - 1][k] + students(j));
                    }
                }
            }
        }

        s = 0;
        for (int i = 0; i < (1 << n); i++) {
            s = big(s, mem[m][i]);
            for (int j = 1; j <= m; j++) {
                mem[j][i] = 0;
            }
        }
        printf("%d\n", s);
    }
    return 0;
}