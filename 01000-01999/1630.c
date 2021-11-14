#include <stdio.h>
#define MOD 987654321

/*
문제 : N(N <= 10^6) 이하의 모든 자연수로 나누어 떨어지는 가장 작은 수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 N 이하의 모든 소수를 구한 다음, N 이하의 모든 소수에 대해
N보다 작으면서 가장 큰 해당 소수의 거듭제곱을 모두 곱한 것을 구하면 답이 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스
*/

char sieve[1048576];
int prime[131072];
int pp = 0;

int main(void) {
    int n;
    long long r = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < pp; i++) {
        for (int j = n / prime[i]; j; j /= prime[i]) r = (r * prime[i]) % MOD;
    }
    printf("%lld", r);
    return 0;
}