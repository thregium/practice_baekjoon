#include <stdio.h>
#define MOD 1000000007

/*
문제 : 길이 L(L <= 10^6)의 A, C, G, T로 이루어진 문자열이 주어질 때, A, C, G, T를 고르는 방법의 가짓수를 구한다.
다른 위치에 있는 같은 문자는 다른 것이다.

해결 방법 : A, C, G, T의 개수를 각각 센 다음 전부 곱하면 된다.

주요 알고리즘 : 수학, 조합론
*/

char s[1048576];
long long cnt[4];

int main(void) {
    long long l, r;
    scanf("%lld", &l);
    scanf("%s", s);
    for (int i = 0; i < l; i++) {
        if (s[i] == 'A') cnt[0]++;
        else if (s[i] == 'C') cnt[1]++;
        else if (s[i] == 'G') cnt[2]++;
        else cnt[3]++;
    }
    printf("%lld", cnt[0] * cnt[1] % MOD * cnt[2] % MOD * cnt[3] % MOD);
    return 0;
}