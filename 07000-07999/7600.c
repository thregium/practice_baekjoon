#include <stdio.h>
#include <ctype.h>

/*
문제 : 주어진 길이 250 이하의 문자열에 알파벳이 몇 가지 있는지 구한다. 대소문자는 구별하지 않는다.

해결 방법 : 문자열을 확인하며 만약 알파벳이 있는 경우 각 알파벳의 수를 센다. 대소문자를 같이 셀 수 있도록 경우를 나눈다.
그 다음 모든 알파벳에 대해 1회 이상 나온 알파벳의 수를 세면 된다.

주요 알고리즘 : 문자열

출처 : NZPC 2008 F번
*/

char s[512];
int cnt[26];

int main(void) {
    int r;
    while (1) {
        fgets(s, 256, stdin);
        if (s[0] == '#') break;
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) cnt[s[i] - 'A']++;
            if (islower(s[i])) cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) r++;
            cnt[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}