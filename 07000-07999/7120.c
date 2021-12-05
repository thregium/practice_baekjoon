#include <stdio.h>

/*
문제 : 250자 이하의 문자열(소문자)이 주어질 때, 연속한 문자들의 중복을 제거하여 출력한다.

해결 방법 : 문자열을 입력받은 다음, 다음 문자와 다른 문자들만 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : LtOI 12II 1번
*/

char s[256];

int main(void) {
    scanf("%s", &s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == s[i + 1]) continue;
        else printf("%c", s[i]);
    }
    return 0;
}