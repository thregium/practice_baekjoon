#include <stdio.h>

/*
문제 : 12개월동안 어떠한 상품의 변화가 주어질 때, 1번의 거래로 M(M <= 500)의 자본금에서
얻을 수 있는 최대 수익을 내는 구간과 그 때의 수익을 구한다. 그러한 구간이 여럿인 경우
가장 많이 사고 파는 경우를 구간으로 정한다. 상품 가격은 모든 달에서 다르다.
수익을 낼 수 없는 경우 "IMPOSSIBLE"을 출력한다.

해결 방법 : 달의 수가 적으므로 모든 달에 대해서 답을 확인한 다음 가장 수익이 많은 구간을 찾고
그 답을 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : GCJ 2011AQ B2번
*/

int p[16];

int main(void) {
    int t, m, a, b, best;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &m);
        for (int i = 1; i <= 12; i++) {
            scanf("%d", &p[i]);
        }
        p[0] = 103000;
        a = 0, b = 0, best = 1;
        for (int i = 1; i <= 12; i++) {
            if (p[i] > m) continue;
            for (int j = i + 1; j <= 12; j++) {
                if (m / p[i] * (p[j] - p[i]) > best ||
                    (m / p[i] * (p[j] - p[i]) == best && m / p[i] > m / p[a])) {
                    a = i, b = j, best = m / p[i] * (p[j] - p[i]);
                }
            }
        }
        if (a == 0) printf("Case #%d: IMPOSSIBLE\n", tt);
        else printf("Case #%d: %d %d %d\n", tt, a, b, best);
    }
    return 0;
}