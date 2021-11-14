#include <stdio.h>

/*
문제 : N(N <= 2 * 10^8) 이하의 모든 자연수의 실질적 약수의 합을 구한다.

해결 방법 : 2부터 N까지 수들을 돌면서 1을 제외한 약수의 합을 구하고 2부터 N까지의 합을 빼면 된다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    long long n, r = 0;
    scanf("%lld", &n);
    for (long long i = 2; i <= n; i++) {
        r += n / i * i;
        r %= 1000000;
    }
    r -= (2 + n) * (n - 1) / 2;
    r %= 1000000;
    if (r < 0) r += 1000000;
    printf("%lld", r);
    return 0;
}