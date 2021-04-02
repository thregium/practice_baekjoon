#include <stdio.h>

int fd[16][16], sel[3], me[16][16];
int n, m, d, best = 0;

void sim(void) {
    int t, c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) me[i][j] = fd[i][j];
    }
    for (int v = 0; v < n; v++) {
        for (int i = 0; i < 3; i++) {
            t = 1;
            for (int di = 1; di <= d; di++) {
                for (int x = -di + 1; x < di; x++) {
                    if (di - (x < 0 ? -x : x) < n && sel[i] + x > 0 && sel[i] + x <= m && me[di - (x < 0 ? -x : x)][sel[i] + x]) {
                        me[di - (x < 0 ? -x : x)][sel[i] + x] -= 2;
                        t = 0;
                        break;
                    }
                }
                if (!t) break;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (me[1][j] < 0) c++;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                if (me[i + 1][j] < 0) {
                    me[i][j] = 0;
                    c++;
                }
                else me[i][j] = me[i + 1][j];
            }
        }
        for (int j = 1; j <= m; j++) me[n][j] = 0;
    }
    if (c > best) best = c;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &fd[i][j]);
        }
    }
    for (sel[0] = 1; sel[0] <= m; sel[0]++) {
        for (sel[1] = sel[0] + 1; sel[1] <= m; sel[1]++) {
            for (sel[2] = sel[1] + 1; sel[2] <= m; sel[2]++) {
                sim();
            }
        }
    }
    printf("%d", best);
    return 0;
}