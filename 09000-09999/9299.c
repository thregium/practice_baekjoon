#include <stdio.h>

/*
문제 : N(N <= 100)차 다항식이 주어질 때, 이 다항식을 미분한 결과를 구한다.

해결 방법 : 다항식의 차수는 N - 1이 되고, 각 항의 계수는 위 차수의 계수 * (위 차수)이다.

주요 알고리즘 : 수학, 미적분학

출처 : UVa 2012 D번
*/

int main(void) {
    int t, n, x, l;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        printf("Case %d: %d ", tt, n - 1);
        l = 0;
        for (int i = n; i >= 0; i--) {
            scanf("%d", &x);
            if (i < n) printf("%d ", (i + 1) * l);
            l = x;
        }
        printf("\n");
    }
    return 0;
}