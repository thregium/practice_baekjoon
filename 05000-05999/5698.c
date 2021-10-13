#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 20자 이하의 단어가 50개 이하로 있는 문장이 주어질 때, 이 문장의 첫 자가 모두 같은지 구한다.
대소문자는 구별하지 않는다. 단어는 알파벳으로 이루어져 있고, 단어는 공백으로 구분된다.

해결 방법 : strtok으로 각 단어를 입력받으며 해당 단어의 첫 문자가 첫 문자와 같은지 매번 확인하면 된다.
단, 각 문자들에는 tolower로 대소문자가 같도록 해야 한다. 한 번이라도 다른 문자가 있다면 다른 것이고, 없다면 같은 것이다.

주요 알고리즘 : 문자열, 파싱, 구현

출처 : Latin 2010 F번
*/

char buff[2048];

int main(void) {
    int ok;
    char st, *t;
    while (1) {
        fgets(buff, 2000, stdin);
        if (buff[0] == '*') break;
        st = tolower(buff[0]);
        ok = 1;
        t = strtok(buff, " ");
        while (t != NULL) {
            t = strtok(NULL, " ");
            if (t == NULL) break;
            if (tolower(t[0]) != st) ok = 0;
        }
        printf("%c\n", ok ? 'Y' : 'N');
    }
    return 0;
}