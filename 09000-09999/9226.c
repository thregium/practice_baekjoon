#include <stdio.h>

/*
문제 : 주어진 20자 이하의 소문자로 이루어진 단어를 피그라틴어로 바꾼 결과를 출력한다.
피그라틴어는 첫 모음 이후의 문자들을 쓴 후, 그 이전 문자들을 쓰고, ay를 붙이는 방식으로 만든다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 문자열, 구현

출처 : NZPC 2002 A번
*/

char s[32], back[32];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

int main(void) {
    int p, r;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        p = 0, r = 0;
        for (int i = 0; s[i]; i++) {
            if (isvowel(s[i])) r++;
            if (r) printf("%c", s[i]);
            else back[p++] = s[i];
        }
        back[p] = '\0';
        printf("%say\n", back);
    }
    return 0;
}