#include <stdio.h>

/*
문제 : 구간 [A, B](A <= B <= 10^14)에서 소수의 N(N >= 2)제곱으로 표현되는 수의 개수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 2부터 10^7까지의 소수를 구한다.
각 소수들마다 거듭제곱 가운데 소수의 거듭제곱으로 표현되는 수들을 각각 세면 된다. 이때 오버플로에 유의한다.

주요 알고리즘 : 수학, 에라토스테네스

출처 : TCHS 33 3번
*/

char sieve[10485760];

int main(void) {
    long long a, b, r = 0;
    scanf("%lld %lld", &a, &b);
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        for (long long j = (long long)i * i;; j *= i) {
            if (j <= b && j >= a) r++;
            if (b / i < j) break;
        }
        for (int j = i * 2; j <= 10000000; j += i) sieve[j] = 1;
    }
    printf("%lld", r);
    return 0;
}