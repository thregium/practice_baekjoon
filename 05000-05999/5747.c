#include <stdio.h>

/*
문제 : N(N <= 100)개의 0 이상인 정수로 이루어진 집합이 2개 있을 때, 두 집합을 적절히 짝지어서 합이 짝수가 되는 쌍이 최소가
되게 한다면 그 때의 합이 짝수인 쌍의 수를 구한다.

해결 방법 : 먼저, 각 집합에서 홀수와 짝수인 수의 개수를 구한다. 그 다음으로는 홀수는 최대한 짝수와, 짝수는 최대한 홀수와
짝짓는 것이 좋으므로 그를 이용해 한 집합의 홀수의 수와 다른 집합의 짝수의 수의 차이가 최소한의 짝수인 쌍의 수가 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : Latin 2006 F번
*/

int main(void) {
    int n, a, xo, xe, yo, ye;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        xo = 0, xe = 0, yo = 0, ye = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            if (a & 1) xo++;
            else xe++;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            if (a & 1) yo++;
            else ye++;
        }
        if (xo > ye) printf("%d\n", xo - ye);
        else printf("%d\n", ye - xo);
    }
    return 0;
}