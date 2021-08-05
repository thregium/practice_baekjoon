#include <stdio.h>

/*
문제 : 10억 이하의 두 자연수 N, K가 주어질 때, N!과 K의 최대공약수를 구한다.

해결 방법 : K를 소인수분해한 다음, N!에 해당 소수가 포함된 횟수만큼 정답에 곱하면 된다. 이를 반복해 답을 얻을 수 있다.

주요 알고리즘 : 수학, 소인수분해

출처 : INC 2007 B번
*/

char sieve[32768];
int primes[4096];
int pp = 0;

int main(void) {
    int n, k, x, r, i, cnt, cnt2;
    for (int i = 2; i < 32768; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j < 32768; j += i) {
            sieve[j] = 1;
        }
    }
    while (scanf("%d %d", &n, &k) != EOF) {
        x = k;
        r = 1;
        for (i = 0; primes[i] * primes[i] <= k; i++) {
            if (x % primes[i]) continue;
            cnt = 0;
            while (!(x % primes[i])) {
                x /= primes[i];
                cnt++;
            }
            cnt2 = 0;
            for (int j = n / primes[i]; j; j /= primes[i]) {
                cnt2 += j;
            }
            if (cnt > cnt2) cnt = cnt2;
            for (int j = 0; j < cnt; j++) {
                r *= primes[i];
            }
        }
        if (n >= x) r *= x;
        printf("%d\n", r);
    }
    return 0;
}