#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 250자 이하의 16진수로 이루어진 문자열을 두 자씩 끊어 아스키 코드로 바꾼 다음 문자로 각각 출력한다.

해결 방법 : 두 자리씩 문자열을 끊은 다음, strtoll 함수를 이용하여 정수로 바꾸고 서식을 통해 문자로 바꾸면 된다.

주요 알고리즘 : 구현, 수학

출처 : Phuket 2015 A번
*/

char s[256], s2[4];

int main(void) {
    int x;
    while (scanf("%s", s) != EOF) {
        for (int i = 0; s[i]; i += 2) {
            s2[0] = s[i];
            s2[1] = s[i + 1];
            x = strtoll(s2, NULL, 16);
            printf("%c", (char)x);
        }
        printf("\n");
    }
    return 0;
}