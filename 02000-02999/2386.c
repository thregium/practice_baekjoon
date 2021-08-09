#include <stdio.h>
#include <ctype.h>

/*
문제 : 250자 이하의 문장과 소문자 하나가 주어질 때, 주어진 알파벳이 문장에 몇 회 나오는지 구한다.
대문자인 경우에도 같은 알파벳인 경우 세야 한다.

해결 방법 : tolower함수를 통해 각 문자들을 소문자로 만든 다음, 주어진 문자와 같은지 확인하고 같은 것을 전부 세면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NZPC 2004 W번
*/

char s[256];

int main(void) {
    int r;
    char c;
    while (1) {
        scanf(" %c", &c);
        if (c == '#') break;
        fgets(s, 253, stdin);
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (tolower(s[i]) == c) r++;
        }
        printf("%c %d\n", c, r);
    }
    return 0;
}