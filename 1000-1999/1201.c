#include <stdio.h>

/*
문제 : 1, 2, ..., N으로 이루어진 순열 가운데 LIS의 길이가 M이고 LDS의 길이가 K인 수열을 아무거나 한 가지 출력한다. 없다면 -1을 출력한다.

해결 방법 : M + K가 N + 1보다 크거나 M * K가 N보다 작은 경우는 만들 수 없다.
수열을 만들 수 있는 경우 수열을 쉽게 만드는 방법으로는 K와 M 가운데 큰 것을 택하여
K가 더 크다면 역순으로 K개씩 끊어서 숫자들을 배치한 후, M개의 문자는 앞에서부터 정방향으로 재배치하는 방식이다.
M이 더 큰 경우 반대로 하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구현
*/

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