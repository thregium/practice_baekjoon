#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 1000자 이하의 문자열이 주어질 때, 이 문자열에 problem이라는 문자열이 포함되었는지 구한다.
대소문자는 신경쓰지 않는다.

해결 방법 : tolower함수를 통해 모든 문자를 소문자로 바꾼 다음 strstr함수를 통해 problem이 포함되었는지 확인하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : NAQ 2012 A번
*/

char s[1024];

int main(void) {
    while (fgets(s, 1013, stdin)) {
        for (int i = 0; s[i]; i++) s[i] = tolower(s[i]);
        printf("%s\n", strstr(s, "problem") ? "yes" : "no");
    }
    return 0;
}