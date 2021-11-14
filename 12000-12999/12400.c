#include <stdio.h>
#include <ctype.h>

/*
문제 : 100자 이하의 소문자와 공백으로 이루어진 문자열이 주어지면, 이 문자열을 암호화되지 않은 형태로 바꾸어 출력한다.
암호문은 평문의 문자를 일대일 대응하여 만들어져 있다. 또한, 원래 문자와 같지 않다.

해결 방법 : 예제에 q와 z를 제외한 모든 문자는 들어있다. 그리고 q와 z가 서로 q와 z를 바꾼 것이기 때문에
q는 z로, z는 q로 가야 한다. 이를 이용해 복호화를 진행하고 이를 출력하면 된다.

주요 알고리즘 : 구현, 애드 혹

출처 : GCJ 2012Q A1번
*/

char s[128];
const char* crypt = "yhesocvxduiglbkrztnwjpfmaq";

int main(void) {
    int t;
    scanf("%d", &t);
    getchar();
    for (int tt = 1; tt <= t; tt++) {
        fgets(s, 120, stdin);
        printf("Case #%d: ", tt);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) printf("%c", crypt[s[i] - 'a']);
            else if (s[i] == ' ' || s[i] == '\n') printf("%c", s[i]);
            else return 1;
        }
    }
    return 0;
}