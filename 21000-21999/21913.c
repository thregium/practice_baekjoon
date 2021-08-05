#include <stdio.h>
#define MOD 1000000007

/*
문제 : 1부터 N(N <= 10^6)까지의 자연수로 이루어진 순열 가운데 인접한 두 수의 나머지가 전부 2 이하인 순열의 수를 구한다.

해결 방법 : 추가 예정

주요 알고리즘 : DP, 정수론

출처 : SEERC 2020 I번
*/

int perms[1048576];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    if (n <= 3) {
        printf("%d", n == 1 ? 1 : n == 2 ? 2 : 6);
        return 0;
    }
    perms[n - 1] = 1;
    for (int i = n - 2; i > 2; i--) {
        perms[i] = perms[i + 1] + 1;
        for (int j = i * 2 - 1; j < n; j += i) {
            perms[i] = ((long long)perms[i] + perms[j] + perms[j + 1] + perms[j + 2]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        r = (r + perms[i]) % MOD;
    }
    printf("%lld", (long long)r * n * 2 % MOD);
    return 0;
}