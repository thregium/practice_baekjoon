#include <stdio.h>

/*
문제 : 주어진 소문자 20자 이하의 문자열이 발음 가능한지 구한다. 모음이 1개 이상 있고, 'e'나 'i'를 제외한 같은 글자가
2번 이상 연속해서 오지 않으며, 자음이나 모음이 3연속으로 오지 않으면 발음 가능한 것이다.

해결 방법 : 문자열을 입력받은 다음 모음이 있는지 확인한다. 없다면 발음 불가능하다. 그 다음으로는 문자열을 살피면서
3연속으로 자음이나 모음이 나오는 경우, 같은 글자가 2연속(e, i 제외)으로 나오는 경우를 확인한다. 그러한 경우가 있다면
발음 불가능하고 없다면 발음 가능하다.

주요 알고리즘 : 구현, 문자열

출처 : MidC 2000 B번
*/

char s[32];
int chk[32];
const char* vow = "aeiou";

int main(void) {
    int r;
    while (1) {
        scanf("%s", s);
        if (s[0] == 'e' && s[1] == 'n' && s[2] == 'd' && s[3] == '\0') break;
        r = 0;
        for (int i = 0; s[i]; i++) {
            chk[i] = 0;
            for (int j = 0; j < 5; j++) {
                if (s[i] == vow[j]) {
                    r = 1;
                    chk[i] = 1;
                }
            }
        }
        for (int i = 1; s[i]; i++) {
            if (i >= 2 && (chk[i] + chk[i - 1] + chk[i - 2] == 3 || chk[i] + chk[i - 1] + chk[i - 2] == 0)) r = 0;
            if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') r = 0;
        }
        printf("<%s> is %s.\n", s, r ? "acceptable" : "not acceptable");
    }
    return 0;
}