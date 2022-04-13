#include <stdio.h>

/*
문제 : M(M <= 2000)개의 절과 N(N <= 2000)개의 변수가 있을때, 각 절을 OR한 다음 AND 하였을 때
답이 참인 경우가 있는 지 확인하고 있다면 그러한 방법을 출력한다. 전체 항의 수는 3000 이하다.
또한, 각 절에는 1인 값이 최대 1개이다.

해결 방법 : 우선 모든 값들을 0으로 맞춘 다음, 모든 절이 만족하거나, 1이 없는 절이 만족하지 않는
경우가 나올 때 까지 반복한다. 1이 있는 절이 만족하지 않는다면 그 변수의 값을 1로 바꾸고 반복한다.
1이 없는 절이 만족하지 않는 경우 실패한 것이므로 참인 경우가 없고,
만족하는 경우에는 그때의 각 변수 값들을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 시뮬레이션

출처 : GCJ 2008A B2번
*/

int cust[2048][6144], custt[2048], res[2048];

int main(void) {
    int t, n, m, ok, good, malt, poss;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &custt[i]);
            for (int j = 0; j < custt[i] * 2; j += 2) {
                scanf("%d %d", &cust[i][j], &cust[i][j + 1]);
            }
        }
        for (int i = 1; i <= n; i++) {
            res[i] = 0;
        }
        poss = 1;
        while (1) {
            good = 1;
            for (int i = 0; i < m; i++) {
                ok = 0, malt = 0;
                for (int j = 0; j < custt[i] * 2; j += 2) {
                    if (res[cust[i][j]] == cust[i][j + 1]) {
                        ok = 1;
                    }
                    if (cust[i][j + 1]) malt = 1;
                }
                if (!ok) {
                    if (malt) {
                        for (int j = 0; j < custt[i] * 2; j += 2) {
                            if (res[cust[i][j]] < cust[i][j + 1]) {
                                res[cust[i][j]] = 1;
                            }
                        }
                    }
                    else poss = 0;
                    good = 0;
                }
                if (!good) break;
            }
            if (good || !poss) break;
        }

        if (poss == 0) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
        }
        else {
            printf("Case #%d: ", tt);
            for (int i = 1; i <= n; i++) {
                printf("%d%c", res[i], i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}