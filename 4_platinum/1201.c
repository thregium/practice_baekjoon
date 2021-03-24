#include <stdio.h>

int a[512], mem[512], chk[512];

/*
void track(int n, int r) {
    if (n == r) {
        int inc = 1, dec = 1;
        for (int i = 0; i < n; i++) mem[i] = 0;
        for (int i = 0; i < n; i++) {
            mem[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] > a[i] && mem[j] + 1 > mem[i]) {
                    mem[i] = mem[j] + 1;
                    if (mem[i] > inc) inc = mem[i];
                }
            }
        }
        for (int i = 0; i < n; i++) mem[i] = 0;
        for (int i = 0; i < n; i++) {
            mem[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i] && mem[j] + 1 > mem[i]) {
                    mem[i] = mem[j] + 1;
                    if (mem[i] > dec) dec = mem[i];
                }
            }
        }
        cnt[inc][dec]++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (chk[i]) continue;
        a[r] = i;
        chk[i] = 1;
        track(n, r + 1);
        chk[i] = 0;
    }
}
*/

int main(void) {
    int n, m, k, x, rv, md, l;
    scanf("%d %d %d", &n, &m, &k);
    //scanf("%d", &n);
    //for (int n = 1; n <= 500; n++) {
        //for (int m = 1; m <= n; m++) {
            //for (int k = 1; k <= n; k++) {
                if (m + k > n + 1 || m * k < n) {
                    printf("-1\n");
                    //continue;
                }
                else if (m >= k) {
                    x = (n + m - 1) / m;
                    rv = k - x;
                    md = (n + m - 1) % m + 1;
                    for (int i = 0; i < x; i++) {
                        l = 0;
                        if (i == 0) {
                            for (int j = 1; j <= md; j++) {
                                if (rv) {
                                    a[j] = n - (k - x) + rv--;
                                    l = j;
                                    if (j == md) rv++;
                                }
                                else a[j] = m * (x - 1) + j - l;
                            }
                        }
                        else {
                            for (int j = 1; j <= m; j++) {
                                if (rv > 1 || (rv == 1 && j < m - 1)) {
                                    a[j + (i - 1) * m + md] = n - (md + (i - 1) * m) - l;
                                    rv--;
                                    l = j;
                                }
                                else a[j + (i - 1) * m + md] = m * (x - 1 - i) + j - l;
                            }
                        }
                    }

                    for (int i = 1; i <= n; i++) {
                        printf("%d ", a[i]);
                    }
                }
                else {
                    x = (n + k - 1) / k;
                    rv = m - x;
                    md = (n + k - 1) % k + 1;
                    for (int i = 0; i < x; i++) {
                        l = 0;
                        if (i == 0) {
                            for (int j = 1; j <= md; j++) {
                                if (rv) {
                                    a[j] = (m - x + 1) - rv--;
                                    l = j;
                                    if (j == md) rv++;
                                }
                                else a[j] = md - j + 1 + l;
                            }
                        }
                        else {
                            for (int j = 1; j <= k; j++) {
                                if (rv > 1 || (rv == 1 && j < k - 1)) {
                                    a[j + (i - 1) * k + md] = (k * (i - 1) + md) + l + 1;
                                    rv--;
                                    l = j;
                                }
                                else a[j + (i - 1) * k + md] = k * i + md - j + l + 1;
                            }
                        }
                    }

                    for (int i = 1; i <= n; i++) {
                        printf("%d ", a[i]);
                    }
                }
                /*
                int inc = 1, dec = 1;
                for (int i = 1; i <= n; i++) mem[i] = 0;
                for (int i = 1; i <= n; i++) {
                    mem[i] = 1;
                    for (int j = 1; j < i; j++) {
                        if (a[j] < a[i] && mem[j] + 1 > mem[i]) {
                            mem[i] = mem[j] + 1;
                            if (mem[i] > inc) inc = mem[i];
                        }
                    }
                }
                for (int i = 1; i <= n; i++) mem[i] = 0;
                for (int i = 1; i <= n; i++) {
                    mem[i] = 1;
                    for (int j = 1; j < i; j++) {
                        if (a[j] > a[i] && mem[j] + 1 > mem[i]) {
                            mem[i] = mem[j] + 1;
                            if (mem[i] > dec) dec = mem[i];
                        }
                    }
                }
                printf("n = %d, m = %d, k = %d, inc = %d, dec = %d ", n, m, k, inc, dec);
                for (int i = 1; i <= n; i++) chk[a[i]]++;
                for (int i = 1; i <= n; i++) {
                    if (chk[i] != 1) {
                        printf("ERROR!\n");
                        return 0;
                    }
                    chk[i] = 0;
                }
                if (inc == m && dec == k) printf("OK\n");
                else {
                    printf("ERROR!\n");
                    return 0;
                }
                */
            //}
        //}
    //}
    return 0;
}