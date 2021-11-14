#include <stdio.h>

/*
문제 : 4 * 10^9 이하의 음이 아닌 정수 N이 주어질 때, 이 수와 같거나 크면서 소수인 가장 작은 수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 65536 이하의 모든 소수를 구한 후, N 이상의 수마다 그러한 소수들로 전부 나누어 본다.
만약 나누어 떨어지는 경우가 있다면 소수가 아닌 것이므로 다음 수를 보고, 없다면 소수이므로 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : Waterloo 120715 B번
*/

char sieve[65536];
int prime[8192];
int pp = 0;

int main(void) {
    int t, x;
    long long n;
    for (int i = 2; i < 65536; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j < 65536; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        if (n <= 1) {
            printf("2\n");
            continue;
        }
        for (long long i = n;; i++) {
            x = 1;
            for (int j = 0; (long long)prime[j] * prime[j] <= i; j++) {
                if (i % prime[j] == 0) {
                    x = 0;
                    break;
                }
                if (j >= 65536) return 1;
            }
            if (x) {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}