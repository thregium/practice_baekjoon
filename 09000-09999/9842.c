#include <stdio.h>

/*
문제 : N(N <= 10000)번째 소수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용한다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : NOIS 2008 1번
*/

char sieve[131072];
int prime[10240];
int pp = 0;

int main(void) {
    int n;
    for (int i = 2; pp < 10000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j < 131072; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    printf("%d", prime[n - 1]);
    return 0;
}
