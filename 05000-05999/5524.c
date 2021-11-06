#include <stdio.h>
#include <ctype.h>

/*
문제 : 20자 이하의 문자열(대소문자) N(N <= 100)개가 주어질 때, 각 문자열을 소문자로 변환한 것을 출력한다.

해결 방법 : tolower()함수를 이용한다.

주요 알고리즘 : 구현, 문자열

출처 : JOI 2013 P3 / 2014 P4번
*/

char s[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) printf("%c", tolower(s[j]));
        printf("\n");
    }
    return 0;
}