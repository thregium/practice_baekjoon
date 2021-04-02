#include <stdio.h>

char arr[1024][1024];
int mem[1024][1024];

int find_ans(int n, int m) {
    int r = 0, rt;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                rt = 1;
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        if (arr[i + x][j + y] == 0) {
                            rt = 0;
                            break;
                        }
                    }
                    if (rt == 0) break;
                }
                if (rt) {
                    if (k > r) r = k;
                }
            }
        }
    }

    return r;
}

int main(void) {
    int n, m, r, rr;
    scanf("%d %d", &n, &m);
    /*
    for (long long tt = 0; tt < 1LL << (n * m); tt++) {
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = (tt >> (m * (i - 1) + (j - 1))) % 2;
            }
            
            scanf("%s", arr[i] + 1);
            for (int j = 1; j <= n; j++) {
                arr[i][j] -= 48;
            }
            
        }
        rr = find_ans(n, m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mem[i][j] = mem[i - 1][j - 1] + 1;
                for (int k = 0; k <= mem[i - 1][j - 1]; k++) {
                    if (!arr[i][j - k] || !arr[i - k][j]) {
                        mem[i][j] = k;
                        break;
                    }
                }
                if (mem[i][j] > r) r = mem[i][j];
            }
        }
        //printf("%d", r * r);
        if (r != rr) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    printf("%d", arr[i][j]);
                }
                printf("\n");
            }
            printf("\nr = %d, rr = %d\n", r, rr);
        }
    }
    */


    return 0;
}