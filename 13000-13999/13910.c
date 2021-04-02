#include <stdio.h>
#define INF 1234567890

int s[128], work[128][10240], s2[10240], mem[2][10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r, w = 1;
    scanf("%d %d", &n, &m);
    //if (m > 80) return 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            mem[j][i] = INF;
        }
    }

    mem[0][0] = 0;
    /*
    work[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (work[i - 1][j]) work[i][j] = 1;
            //if (work[i - 1][j] && j >= s[i]) work[i][j - s[i]] = 1;
            if (work[i - 1][j] && j + s[i] <= n) work[i][j + s[i]] = 1;
        }
    }
    */
    for (int i = 1; i <= m; i++) {
        r = 1;
        for (int k = 1; k < w; k++) {
            if (s2[k] == s[i]) {
                r = 0;
                break;
            }
        }
        if (r) {
            s2[w++] = s[i];
        }
        for (int j = i + 1; j <= m; j++) {
            r = 1;
            for (int k = 1; k < w; k++) {
                if (s2[k] == s[i] + s[j]) {
                    r = 0;
                    break;
                }
            }
            if (r) {
                s2[w++] = s[i] + s[j];
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        if(work[2][i]) s2[w++] = i;
        //if (w > 5000) return 1;
    }
    */

    for (int i = 1; i < w; i++) {
        for (int j = 0; j <= n; j++) {
            mem[1][j] = small(mem[0][j], s2[i] > j ? INF : small(mem[1][j - s2[i]], mem[0][j - s2[i]]) + 1);
        }
        for (int j = 0; j <= n; j++) {
            mem[0][j] = mem[1][j];
        }
    }

    printf("%d", mem[0][n] == INF ? -1 : mem[0][n]);
    return 0;
}