#include <stdio.h>
#define MOD 123456789

/*
문제 : 자연수 N(N <= 40000)에 대해 소수의 합으로 N을 만드는 방법의 가짓수를 구한다. 순서는 상관하지 않는다.

해결 방법 : 40000 이하의 소수를 모두 구한 다음, 냅색을 통해 N을 만드는 방법의 가짓수를 구하면 된다.
같은 소수를 여러 번 쓸 수 있음과 연산 횟수가 많음에 유의한다.

주요 알고리즘 : DP, 냅색, 에라토스테네스

출처 : 홍익대 2018 G번
*/

char sieve[40960];
int prime[5120], mem[40960];
int pp = 0;

int main(void) {
    int n;
    for (int i = 2; i <= 40000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 40000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    mem[0] = 1;
    for (int i = 0; i < pp; i++) {
        if (prime[i] > n) break;
        for (int j = 0; j <= n; j++) {
            if (j < prime[i]) mem[j] = mem[j];
            else mem[j] = (mem[j] + mem[j - prime[i]]) % MOD;
        }
    }
    printf("%d", mem[n]);
    return 0;
}