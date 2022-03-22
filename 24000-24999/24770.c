#include <stdio.h>

/*
문제 : N(N <= 10)가지의 티켓을 사는 방법 가운데 가장 좋은 것을 고른다.
티켓은 M(M <= 20)장 넘게 사지 않는다.
각 사는 방법은 A$로 B장의 티켓을 사는 것이다. 좋은 것은 더 가격 대비 많은 티켓을 사는 것이고,
그 값이 같다면 더 많은 티켓을 사는 것이다.

해결 방법 : 분수의 형태로 생각하여 더 분자 / 분모가 큰 것을 찾아나가면 된다.
값 비교는 분모와 분자를 교대로 곱하여 비교하는 방식으로 할 수 있다.

주요 알고리즘 : 수학

출처 : VTH 2014 F번
*/

int main(void) {
    int n, m, bu, bd, u, d;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        bu = -1, bd = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &u, &d);
            if (u > m) continue;
            if (u * bd > bu * d || (u * bd == bu * d && u > bu)) {
                bu = u;
                bd = d;
            }
        }
        if (bu < 0) printf("No suitable tickets offered\n");
        else printf("Buy %d tickets for $%d\n", bu, bd);
    }
    return 0;
}
