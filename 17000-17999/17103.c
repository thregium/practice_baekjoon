#include <stdio.h>

/*
문제 : 2보다 크고 10^6 이하인 짝수 N이 주어질 때, 더해서 N이 되는 소수 쌍의 개수를 구한다. 순서만 다른 것은 같은 경우이다.

해결 방법 : 10^6 이하의 모든 소수를 에라토스테네스의 체로 먼저 걸러낸다. 그리고 1부터 N / 2까지 확인하며
N - i와 i가 모두 소수인 i의 개수를 세면 된다.

주요 알고리즘 : 수학, 에라토스테네스
*/

char sieve[1048576];

int main(void) {
    int t, n, r = 0;
    sieve[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 1; i <= n - i; i++) {
            if (!(sieve[i] || sieve[n - i])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}