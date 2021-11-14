#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^9) 이하에서 반전한 수(각 자릿수를 9에서 뺀 수로 바꾼 수)와 원래 수의 곱이 가장 큰 수의 반전한 곱을 구한다.

해결 방법 : 만약 N이 5 이상으로 시작한다면 50...0이 반전한 곱이 가장 큰 것을 알 수 있다. 그 수의 반전한 곱을 구하면 된다.
4 이하인 경우는 N이 해당 수 이하에서 가장 크므로 N의 반전한 곱을 구한다.

주요 알고리즘 : 수학

출처 : 고려대 2016 H번
*/

int main(void) {
    int t, n;
    long long a, orig, r, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        a = 1;
        orig = n;

        while (n > 0) {
            r += a * (abs(9 - (n % 10)));
            n /= 10;
            a *= 10;
        }
        b = (a >> 1) - 1;
        a >>= 1;

        if (orig >= b) printf("%lld\n", a * b);
        else printf("%lld\n", orig * r);
    }
    return 0;
}