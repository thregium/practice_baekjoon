#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 문자열을 뒤집은 문자열을 출력한다.

해결 방법 : 문자열을 받은 후 길이를 확인하고 역순으로 문자열을 채워나가면 된다.

주요 알고리즘 : 문자열, 구현

출처 : MidAt 2006 P번
*/

char s[128], r[128];

int main(void) {
    int l;
    while (1) {
        fgets(s, 100, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (!strcmp(s, "***")) break;
        l = strlen(s);
        for (int i = 0; i < l; i++) {
            r[l - i - 1] = s[i];
        }
        r[l] = '\0';
        printf("%s\n", r);
    }
    return 0;
}