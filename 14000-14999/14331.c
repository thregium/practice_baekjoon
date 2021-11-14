#include <stdio.h>
#define MOD 1000000007

/*
문제 : 1000자 이하의 문자열이 주어질 때, 이 문자열에서 앞뒤로 3개의 문자 가운데 하나의 문자를 골라 만들 수 있는
문자열의 개수를 구한다.

해결 방법 : 앞뒤로 매번 문자를 보면서 서로 다른 문자의 수의 개수를 곱해가면 된다.

주요 알고리즘 : 수학, 조합론

출처 : GCJ 2017A A2번
*/

char s[1024];

int main(void) {
    int t, n;
    long long r = 1;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        if (s[1] == '\0') {
            printf("Case #%d: 1\n", tt);
            continue;
        }
        r = 1;
        for (int i = 0; s[i]; i++) {
            if (i == 0) {
                if (s[i] != s[i + 1]) r *= 2;
            }
            else if (s[i + 1] == '\0') {
                if (s[i] != s[i - 1]) r = (r * 2) % MOD;
            }
            else {
                if (s[i - 1] == s[i] && s[i] == s[i + 1]) continue;
                else if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1]) r = (r * 3) % MOD;
                else r = (r * 2) % MOD;
            }
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}