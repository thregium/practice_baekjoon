#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 70자 이하의 문자열을 뒤집은 결과를 출력한다.

해결 방법 : 문자열의 길이를 확인한 후 뒤에서부터 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : SWERC 1996 PC번
*/

char s[128];

int main(void) {
    int t, len = 1;
    scanf("%d\n", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(s, 100, stdin);
        len = strlen(s);
        if (s[len - 1] == '\n') {
            //마지막 글자가 개행인 경우 개행을 제거한다.
            s[len - 1] = '\0';
            len--;
        }
        for (int i = 0, j = len - 1; i < len; i++, j--) {
            printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}