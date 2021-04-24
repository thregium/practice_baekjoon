#include <stdio.h>

/*
문제 : 두 true / false 사이에 AND / OR가 주어질 때 주어진 연산의 결과를 출력한다.

해결 방법 : 가운데 문자열이 OR와 AND인 경우를 나누어 구현한다.

주요 알고리즘 : 구현, 문자열

출처 : AIPO 2016P 1번
*/

char s[3][8];

int main(void) {
    scanf("%s %s %s", s[0], s[1], s[2]);
    if (s[1][0] == 'O') {
        printf("%s", (s[0][0] == 't' || s[2][0] == 't') ? "true" : "false");
    }
    else {
        printf("%s", (s[0][0] == 't' && s[2][0] == 't') ? "true" : "false");
    }
    return 0;
}