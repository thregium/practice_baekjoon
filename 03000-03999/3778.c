#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 두 개의 길이 45 이하의 소문자로만 이루어진 문자열이 주어질 때, 두 문자열에서 문자들을 적절히 삭제하여
애너그램 관계가 되도록 하는 최소한의 삭제 횟수를 구한다.

해결 방법 : 만약 한 곳에서는 있는 문자가 다른 곳에서는 없다면 한 쪽의 문자를 삭제해야 한다.
따라서, 필요한 삭제 횟수는 각 문자의 등장 횟수를 센 다음, 모든 문자에 대해 두 문자열의 등장 횟수의 차이를 구하면 된다.

주요 알고리즘 : 문자열

출처 : SEERC 2005 H번
*/

char s[64];
int cnt1[26], cnt2[26];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int tt = 1; tt <= n; tt++) {
        for (int i = 0; i < 26; i++) {
            cnt1[i] = 0;
            cnt2[i] = 0;
        }
        fgets(s, 60, stdin);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) cnt1[s[i] - 'a']++;
        }
        fgets(s, 60, stdin);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) cnt2[s[i] - 'a']++;
        }
        r = 0;
        for (int i = 0; i < 26; i++) {
            r += abs(cnt1[i] - cnt2[i]);
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}