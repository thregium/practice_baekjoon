#include <stdio.h>

int nxt[1024][128], pre[1024], b[1024], c[1024], r[1024];

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &b[j]);
            if (j > 0) {
                nxt[b[j - 1]][++nxt[b[j - 1]][0]] = b[j];
                pre[b[j]]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 1; j <= n; j++) {
            if (pre[j] == 0) {
                if (c[j]) continue;
                for (int k = 1; k <= nxt[j][0]; k++) {
                    pre[nxt[j][k]]--;
                }
                t = 1;
                c[j] = 1;
                r[i] = j;
                break;
            }
        }
        if (!t) {
            r[0] = -1;
            break;
        }
    }
    if (r[0] < 0) printf("0");
    else {
        for (int i = 0; i < n; i++) {
            printf("%d ", r[i]);
        }
    }
    return 0;
}