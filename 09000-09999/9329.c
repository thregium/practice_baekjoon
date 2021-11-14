#include <stdio.h>

/*
문제 : N(N <= 10)가지 상금을 얻는 방법이 주어진다. K(K <= 30)가지 주어진 스티커를 모으면 상금을 얻을 수 있다.
한 스티커는 많아야 하나의 상금에만 쓰인다면, 각 스티커를 갖은 개수가 주어지면 얻을 수 있는 최대 상금을 구한다.

해결 방법 : 각 스티커는 많아야 하나의 상금에만 쓰이므로 각 상금마다 교환할 수 있는 최대의 스티커를 교환한다.
해당 스티커 가운데 가장 적은 스티커의 개수 * 상금을 교환 가능하다. 이를 전부 더하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : Rocky 2013 A번
*/

int stk[16][32], cnt[32];

int main(void) {
    int t, n, m, r, worst;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &stk[i][0]);
            for (int j = 1; j <= stk[i][0]; j++) {
                scanf("%d", &stk[i][j]);
            }
            scanf("%d", &stk[i][31]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &cnt[i]);
        }

        r = 0;
        for (int i = 0; i < n; i++) {
            worst = 103000;
            for (int j = 1; j <= stk[i][0]; j++) {
                if (cnt[stk[i][j]] < worst) worst = cnt[stk[i][j]];
            }
            r += worst * stk[i][31];
        }
        printf("%d\n", r);
    }
    return 0;
}