#include <stdio.h>
#include <string.h>

/*
문제 : 80자 이하의 문장이 주어질 때, 공백, !, $, (, ), * 문자가 나오는 경우 해당 문자들을 퍼센트 인코딩으로 대체한 문장을 출력한다.

해결 방법 : 해당하는 문자가 아니라면 그대로 출력하고, 해당하는 문자가 나오면 %에 아스키 코드를 16진수로 적은 것을
출력하면 된다. 모든 문장이 끝나면 개행을 한다.

주요 알고리즘 : 문자열, 구현

출처 : MidC 2007 B번
*/

char s[128];

int main(void) {
    while (1) {
        fgets(s, 100, stdin);
        if (s[0] == '#') break;
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        for (int i = 0; s[i]; i++) {
            if (s[i] == ' ' || s[i] == '!' || s[i] == '$' || s[i] == '%' || s[i] == '(' || s[i] == ')' || s[i] == '*') {
                printf("%%%x", s[i]);
                continue;
            }
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}