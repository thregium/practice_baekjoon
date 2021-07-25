#include <stdio.h>

/*
문제 : N(N <= 10^15)가지의 상태를 최대 B(B <= 50)비트로 압축 가능한지 구한다.

해결 방법 : B비트로 나타낼 수 있는 상태는 0비트부터 B비트까지로 각각 나타낼 수 있는 2^i의 합과 같다.
만약 이 값이 N 이상인 경우에는 압축 가능하고, N 미만인 경우에는 압축 불가능하다.

주요 알고리즘 : 수학

출처 : NCPC 2008 B번
*/

int main(void) {
    long long n, b, r = 0;
    scanf("%lld %lld", &n, &b);
    for (int i = 0; i <= b; i++) {
        r += (1LL << i);
    }
    if (r >= n) printf("yes");
    else printf("no");
    return 0;
}