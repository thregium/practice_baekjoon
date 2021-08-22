#include <stdio.h>

/*
문제 : N(N <= 500000)번째 소수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용한다.

주요 알고리즘 : 수학, 에라토스테네스의 체 

출처 : BSIS D번
*/

char sieve[8388608];
int primes[524288];
int pp = 0;

int main(void) {
    int n;
    for (int i = 2; i < 7654321; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i << 1; j < 7654321; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    printf("%d", primes[n - 1]);
    return 0;
}