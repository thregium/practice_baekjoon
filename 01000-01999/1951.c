#include <stdio.h>
#define MOD 1234567

/*
문제 : 자연수 N(N <= 2 * 10^9)이 주어질 때, 1부터 N까지 자릿수 개수의 합을 구한다.

해결 방법 : N의 자릿수 개수마다 답은 (N - N보다 자릿수가 1 작은 수 중 가장 큰 수) * N의 자릿수
+ ((N보다 자릿수가 1 작은 수 중 가장 큰 수)까지의 답)과 같다. 따라서 이 값을 구하면 된다.

주요 알고리즘 : 수학, 케이스 워크
*/

int main(void) {
    long long n;
    scanf("%lld", &n);
    if (n < 10) printf("%lld", n % MOD);
    else if (n < 100) printf("%lld", (9 + (n - 9) * 2) % MOD);
    else if (n < 1000) printf("%lld", (189 + (n - 99) * 3) % MOD);
    else if (n < 10000) printf("%lld", (2889 + (n - 999) * 4) % MOD);
    else if (n < 100000) printf("%lld", (38889 + (n - 9999) * 5) % MOD);
    else if (n < 1000000) printf("%lld", (488889 + (n - 99999) * 6) % MOD);
    else if (n < 10000000) printf("%lld", (5888889 + (n - 999999) * 7) % MOD);
    else if (n < 100000000) printf("%lld", (68888889 + (n - 9999999) * 8) % MOD);
    else if (n < 1000000000) printf("%lld", (788888889 + (n - 99999999) * 9) % MOD);
    else if (n < 10000000000) printf("%lld", (8888888889 + (n - 999999999) * 10) % MOD);
    return 0;
}