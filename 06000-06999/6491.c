#include <stdio.h>

/*
문제 : 자연수 N(N <= 60000)이 주어질 때, N이 완전수인지 부족수인지 과잉수인지 구한다.

해결 방법 : N 미만의 모든 수에 대해 약수인지 확인하고 약수들의 합을 구한다. 이 값을 N과 비교해 답을 찾아내면 된다.

주요 알고리즘 : 브루트 포스, 정수론

출처 : Mid-At 1996 6번
*/

int main(void) {
    int n, s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        s = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) s += i;
        }
        if (s > n) printf("%d ABUNDANT\n", n);
        else if (s == n) printf("%d PERFECT\n", n);
        else printf("%d DEFICIENT\n", n);
    }
    return 0;
}