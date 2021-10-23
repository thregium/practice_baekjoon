#include <stdio.h>

/*
문제 : N(N <= 10^18) 이하의 음이 아닌 정수가 주어질 때, 서로 다른 1개 이상의 음이 아닌 정수의 팩토리얼 합으로
만들 수 있는 수인지 구한다.

해결 방법 : 10^18 이하의 팩토리얼은 모두 20개이다.(0! ~ 20!) 따라서 모든 경우의 수를 직접 찾아보더라도
시간 내로 푸는 것이 가능해진다. 모든 경우의 수를 찾아보며 N과 같은 경우가 있는지를 찾으면 된다.

주요 알고리즘 : 수학, 브루트 포스, 비트마스킹
*/

long long fact[32];

int main(void) {
    long long n, s, r = 0;
    scanf("%lld", &n);
    fact[0] = 1;
    for (int i = 1; i < 20; i++) fact[i] = fact[i - 1] * i;
    for (int i = 1; i < (1 << 20); i++) {
        s = 0;
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) s += fact[j];
        }
        if (n == s) r = 1;
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}