#include <stdio.h>

/*
문제 : N(N <= 200000)개의 자연수(<= 10^9)로 이루어진 배열이 주어진다. 이 배열에서
최대 3개의 수를 바꾸어 정렬된 상태로 만들 수 있는 지 확인하고 그러한 경우 그 방법을 출력한다.

해결 방법 : 경우의 수를 최대한 나누어 해결한다.

주요 알고리즘 : 그리디 알고리즘, 케이스 워크

출처 : 선린 5회 A번
*/

int stk[16], sres[16], chk[16];
int a[204800], na[204800];

void rmvarr(int* a, int n, int m) {
    for (int i = m; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
}

int issorted(int* a, int n, int m) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) return 0;
    }
    return 1;
}

int solve(int n) {
    int on = n, rmv = 0, rmvd, res = 4;
    for (int tt = 0; tt < 4; tt++) {
        n = on;
        for (int i = 0; i < n; i++) na[i] = a[i + 1];
        rmv = 0;
        while (rmv <= 3) {
            n = on - rmv;
            if (issorted(na, n, 0)) break;
            rmvd = 0;
            if (na[0] > na[1]) {
                rmvarr(na, n, 0);
                rmvd = 1;
                stk[rmv++] = 0;
            }
            if (rmvd) continue;
            if (na[n - 1] < na[n - 2]) {
                rmvarr(na, n, n - 1);
                //na[n - 1] = 1000000000;
                rmvd = 1;
                stk[rmv++] = n - 1;
            }
            if (rmvd) continue;
            if (tt & 2) {
                for (int i = 1; i < n - 1; i++) {
                    if (na[i - 1] < na[i] && na[i] > na[i + 1] && na[i - 1] <= na[i + 1]) {
                        rmvarr(na, n, i);
                        //if (tt & 2) na[i] = na[i - 1];
                        //else na[i] = na[i + 1];
                        rmvd = 1;
                        stk[rmv++] = i;
                        break;
                    }
                    if (na[i - 1] > na[i] && na[i] < na[i + 1] && na[i - 1] <= na[i + 1]) {
                        rmvarr(na, n, i);
                        //if (tt & 2) na[i] = na[i - 1];
                        //else na[i] = na[i + 1];
                        rmvd = 1;
                        stk[rmv++] = i;
                        break;
                    }
                }
            }
            else {
                for (int i = n - 1; i >= 1; i--) {
                    if (na[i - 1] < na[i] && na[i] > na[i + 1] && na[i - 1] <= na[i + 1]) {
                        rmvarr(na, n, i);
                        //if (tt & 2) na[i] = na[i - 1];
                        //else na[i] = na[i + 1];
                        rmvd = 1;
                        stk[rmv++] = i;
                        break;
                    }
                    if (na[i - 1] > na[i] && na[i] < na[i + 1] && na[i - 1] <= na[i + 1]) {
                        rmvarr(na, n, i);
                        //if (tt & 2) na[i] = na[i - 1];
                        //else na[i] = na[i + 1];
                        rmvd = 1;
                        stk[rmv++] = i;
                        break;
                    }
                }
            }
            if (rmvd) continue;
            for (int i = 0; i < n - 1; i++) {
                if (tt & 1) {
                    if (na[i] > na[i + 1]) {
                        rmvarr(na, n, i);
                        //na[i] = na[i + 1];
                        rmvd = 1;
                        stk[rmv++] = i;
                        break;
                    }
                }
                else {
                    if (na[i] > na[i + 1]) {
                        rmvarr(na, n, i + 1);
                        //na[i + 1] = na[i];
                        rmvd = 1;
                        stk[rmv++] = i + 1;
                        break;
                    }
                }
            }
        }
        if (rmv < res) {
            res = rmv;
            for (int i = 0; i < res; i++) sres[i] = stk[i];
        }
        n = on;
        
    }
    return res;
}

int main(void) {
    int n, res, slast, ok;
    scanf("%d", &n);
    //for (int i = 1; i <= n; i++) a[i] = 1;
    for (long long i = 0; i < 1; i++) {
        /*
        a[n]++;
        for (int j = n; j > 0; j--) {
            while (a[j] > 5) {
                a[j - 1]++;
                a[j] -= 5;
            }
        }
        if (a[0]) break;
        res = solve(n);
        */
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
        }
        res = solve(n);

        for (int i = 1; i < res; i++) {
            slast = -1;
            for (int j = 0; j < i; j++) chk[j] = 0;
            while (sres[i] > slast) {
                slast = sres[i];
                for (int j = 0; j < i; j++) {
                    if (chk[j]) continue;
                    if (sres[j] <= sres[i]) {
                        chk[j] = 1;
                        sres[i]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) na[i] = a[i + 1];
        for (int i = 0; i < res; i++) {
            slast = -1;
            for (int j = sres[i] - 1; j >= 0; j--) {
                ok = 1;
                for (int k = 0; k < res; k++) {
                    if (sres[k] == j) ok = 0;
                }
                if (ok) {
                    slast = j;
                    break;
                }
            }
            if (slast < 0) na[sres[i]] = 1;
            else na[sres[i]] = na[slast];
        }
        /*
        bres = 4;
        for (int ii = 0; ii < n; ii++) na2[ii] = a[ii + 1];
        for (int ii = 0; ii < n; ii++) {
            for (int iii = 1; iii <= 5; iii++) {
                na2[ii] = iii;
                if (bres > 1 && issorted(na2, n, 0)) bres = 1;
                if (bres <= 2) continue;
                for (int jj = ii + 1; jj < n; jj++) {
                    for (int jjj = 1; jjj <= 5; jjj++) {
                        na2[jj] = jjj;
                        if (bres > 2 && issorted(na2, n, 0)) bres = 2;
                        if (bres <= 3) continue;
                        for (int kk = jj + 1; kk < n; kk++) {
                            for (int kkk = 1; kkk <= 5; kkk++) {
                                na2[kk] = kkk;
                                if (bres > 3 && issorted(na2, n, 0)) bres = 3;
                            }
                            na2[kk] = a[kk + 1];
                        }
                    }
                    na2[jj] = a[jj + 1];
                }
            }
            na2[ii] = a[ii + 1];
        }
        if (issorted(na2, n, 0)) bres = 0;

        if (res != bres) {
            printf("ERROR!\n");
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) {
                printf("%d ", a[i]);
            }
            printf("\nExpected %d but %d\n", bres, res);
            return 1;
        }
        */
        if (res >= 4) {
            printf("NO\n");
            continue;
        }
        if (!issorted(na, n, 0)) {
            printf("ERROR!\n");
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n%d\n", res);
            for (int i = 0; i < n; i++) {
                printf("%d ", na[i]);
            }
            return 1;
        }

        printf("YES\n");
        printf("%d\n", res);
        for (int i = 0; i < res; i++) {
            printf("%d %d\n", sres[i] + 1, na[sres[i]]);
        }

        for (int j = 0; j <= res; j++) {
            sres[j] = 0;
        }
    }
    //printf("OK");
    return 0;
}