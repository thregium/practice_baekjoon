#include <stdio.h>

/*
문제 : A와 B(A <= B <= 100000) 사이의 수 가운데 소인수의 개수가 소수인 수의 개수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 소인수의 개수와 소수 여부를 미리 구해둔 다음,
A와 B 사이 값들을 돌면서 소인수의 개수가 소수인 수들을 세면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : SRM 442 D1A / D2B
*/

char sieve[103000];
int cnt[103000];

int main(void) {
    int a, b, r = 0;
    sieve[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        cnt[i] = 1;
        for (int j = i * 2; j <= 100000; j += i) {
            for (int k = j; k % i == 0; k /= i) cnt[j]++;
            sieve[j] = 1;
        }
    }
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (!sieve[cnt[i]]) r++;
    }
    printf("%d", r);
    return 0;
}