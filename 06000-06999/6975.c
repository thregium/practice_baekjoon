#include <stdio.h>

/*
문제 : N(N <= 32500)이 주어질 때, 이 수가 부족수인지 완전수인지 과잉수인지 구한다.

해결 방법 : 1부터 N - 1까지 모든 수에 대해 약수인지 조사하더라도 시간 초과가 나지 않으므로 전부 조사해보면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : CCC 1996 1번
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) r += i;
        }
        printf("%d is %s number.\n", n, n > r ? "a deficient" : n == r ? "a perfect" : "an abundant");
    }
    return 0;
}