#include <stdio.h>
#include <ctype.h>

/*
문제 : 주어진 200자 이하의 문자열(소문자, 공백)이 팬그램(모든 알파벳을 사용)인지 구한다.

해결 방법 : 문자열에서 각 알파벳의 등장 여부를 체크한다. 그 후 모든 알파벳이 등장하였는지 살피면 된다.

주요 알고리즘 : 문자열, 구현

출처 : Latin 2009 PA번
*/

char s[256], chk[26];

int main(void) {
    int r;
    while (1) {
        fgets(s, 240, stdin);
        if (s[0] == '*') break;
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) chk[s[i] - 'a'] = 1;
            else if (s[i] != ' ' && s[i] != '\n') return 1;
        }
        r = 1;
        for (int i = 0; i < 26; i++) {
            if (chk[i]) chk[i] = 0;
            else r = 0;
        }
        printf("%c\n", r ? 'Y' : 'N');
    }
    return 0;
}