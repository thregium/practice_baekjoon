#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 100자 이하의 숫자와 알파벳으로 이루어진 문자열 S에서 숫자를 제거하면
100자 이하의 알파벳으로 이루어진 문자열 K를 찾을 수 있는지 구한다.

해결 방법 : isalpha() 함수를 사용하여 숫자가 아닌 문자만 새로운 문자열에 복사하고 strstr() 함수를 이용하여
문자열이 있는지 찾으면 된다.

주요 알고리즘 : 문자열, 구현

출처 : 숭실/중앙 2018 G번
*/

char s[128], s2[128], k[128];

int main(void) {
    int p = 0;
    scanf("%s%s", s, k);
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) s2[p++] = s[i];
    }
    if (strstr(s2, k)) printf("1");
    else printf("0");
    return 0;
}