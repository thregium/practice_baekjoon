#include <stdio.h>

/*
문제 : [L, U](-10^6 < L <= U < 10^6) 범위의 소수의 개수와
두 자연수의 곱으로 나타낼 수 있는 소수의 개수를 각각 구한다. 이를 (<= 1000)회 반복한다.

해결 방법 : 각 범위의 소수의 개수는 에라토스테네스의 체로 간단히 구할 수 있고,
두 자연수의 곱으로 나타낼 수 있는 수는 브루트 포스로 구할 수 있다.
T가 많기 때문에 누적 합을 이용해 출력을 최적화시키면 된다.
L이나 U가 음수인 경우는 0인 경우와 같게 처리할 수 있다.

주요 알고리즘 : 수학, 에라토스테네스, 브루트 포스, 누적 합

출처 : Arab 2007 E번
*/

int sieve[1048576], sqrsum[1048576];

int main(void) {
    int l, u;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    for (int i = 1; i * i <= 1000000; i++) {
        for (int j = 1; i * i + j * j <= 1000000; j++) {
            if (!sieve[i * i + j * j]) sqrsum[i * i + j * j] = 1;
        }
    }
    for (int i = 2; i <= 1000000; i++) sieve[i] = (!sieve[i]) + sieve[i - 1];
    for (int i = 2; i <= 1000000; i++) sqrsum[i] += sqrsum[i - 1];
    while (1) {
        scanf("%d %d", &l, &u);
        if (l == -1 && u == -1) break;
        printf("%d %d ", l, u);
        if (l < 1) l = 1;
        if (u < 1) u = 1;
        printf("%d %d\n", sieve[u] - sieve[l - 1], sqrsum[u] - sqrsum[l - 1]);
    }
    return 0;
}