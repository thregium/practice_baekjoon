#include <stdio.h>

/*
문제 : 자연수 N(4 <= N <= 32000)이 주어질 때, 두 소수로 나타내는 방법을 모두 구한다. 순서만 다른 것은 제외한다.

해결 방법 : 에라토스테네스의 체를 이용해 미리 32000 이하의 소수 여부를 저장해둔 다음, 매번 N이 나올 때 마다
2부터 N / 2까지의 수에 대해 i와 N - i가 모두 소수인 쌍을 찾으면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : NAQ 2013 C번
*/

char sieve[32768];

int main(void) {
    int t, n, r;
    for (int i = 2; i <= 32000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 32000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 2; i <= n - i; i++) {
            if (!sieve[i] && !sieve[n - i]) r++;
        }
        printf("%d has %d representation(s)\n", n, r);
        for (int i = 2; i <= n - i; i++) {
            if (!sieve[i] && !sieve[n - i]) {
                printf("%d+%d\n", i, n - i);
            }
        }
        printf("\n");
    }
    return 0;
}