#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 원래 문자열(소문자 + 공백, 30000자 이하)과 암호화 키(소문자)가 주어질 때,
문제에 주어진 방식대로 암호화된 문자열을 출력한다.

해결 방법 : 문제에 주어진대로 구현한다. 나머지 연산을 적절히 사용하면 비교적 간단해진다.

주요 알고리즘 : 문자열, 구현
*/

char s[32768], s2[32768];

int main(void) {
    int l2;
    fgets(s, 32000, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = 0;
    fgets(s2, 32000, stdin);
    if (s2[strlen(s2) - 1] == '\n') s2[strlen(s2) - 1] = 0;
    l2 = strlen(s2);
    for (int i = 0; i < l2; i++) {
        if (!islower(s2[i])) return 1;
    }
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) {
            printf("%c", (s[i] - 'a' + (25 - (s2[i % l2] - 'a'))) % 26 + 'a');
        }
        else if (s[i] == ' ') printf(" ");
        else return 1;
    }
    return 0;
}