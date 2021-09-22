#include <stdio.h>
#include <ctype.h>

/*
문제 : 10^6 이하 길이의 소문자로만 이루어진 문자열이 주어질 때, 이 문자열을 대문자로 변환한 결과를 출력한다.

해결 방법 : toupper 함수를 이용한다.

주요 알고리즘 : 구현

출처 : BAPC 2017P X번
*/

char s[1048576];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        printf("%c", toupper(s[i]));
    }
    return 0;
}