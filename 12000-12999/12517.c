#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 20자 이하 길이의 문자열이 주어질 때, 이 문자열의 마지막 글자가 모음인지 y인지 그 외 자음인지 구한다.

해결 방법 : 마지막 글자를 소문자로 바꾼 다음, y, 모음과 각각 대조해보며 같은 것이 있는지 확인해보면 된다.

주요 알고리즘 : 문자열, 구현

출처 : GCJ 2011E A1번
*/

char s[256];

int main(void) {
    int t, l;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        printf("Case #%d: %s is ruled by ", tt, s);
        l = strlen(s) - 1;
        s[l] = tolower(s[l]);
        if (s[l] == 'y') printf("nobody.\n");
        else if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') printf("a queen.\n");
        else printf("a king.\n");
    }
    return 0;
}