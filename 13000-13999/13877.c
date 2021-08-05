#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 7자리 이하의 10진수를 8진수, 10진수, 16진수로 읽었을 때의 값을 각각 10진수로 구한다.
8진수로 읽을 수 없다면 0을 출력한다.

해결 방법 : 각 수들을 문자열 형태로 입력받은 다음에 8이나 9가 있는지(8진수로 읽을 수 없는지) 확인한 다음
strtoll을 통해 가능한 수에 대해 출력하면 된다.

주요 알고리즘 : 문자열, 수학

출처 : GNY 2016 A번
*/

char s[16];

int main(void) {
    int t, k, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %s", &k, s);
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '9' || s[i] == '8') r = 1;
        }
        if (r) printf("%d 0 %lld %lld\n", k, strtoll(s, NULL, 10), strtoll(s, NULL, 16));
        else printf("%d %lld %lld %lld\n", k, strtoll(s, NULL, 8), strtoll(s, NULL, 10), strtoll(s, NULL, 16));
    }
    return 0;
}
