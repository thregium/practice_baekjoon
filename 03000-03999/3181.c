#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 100자 이하의 소문자와 공백으로 이루어진 문자열이 주어질 때, 이 문자열을 줄인 단어를 만든다.
문자열을 줄인 단어는 각 단어의 맨 앞 글자를 따와서 전부 대문자로 만든 것이다. 단, 10개의 단어는 제외하되,
맨 앞에 있는 경우는 포함한다.

해결 방법 : 첫 문자는 항상 출력하도록 하고, 이후 문자는 앞 글자가 공백이고 현재 글자가 문자라면 출력할지 확인한다.
만약 10개의 단어 가운데 하나라면 출력해서는 안 된다. 그 외의 경우에는 출력하도록 한다. 해당 단어로 시작하는
다른 단어의 일부인 경우는 해당 단어가 아니다.

주요 알고리즘 : 문자열

출처 : CHCI 2005RJ 1번
*/

char s[256];
const char* no[] = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" };

int main(void) {
    int t;
    fgets(s, 120, stdin);
    for (int i = 0; s[i]; i++) {
        if (i == 0) {
            if (!isalpha(s[i])) return 1;
            printf("%c", toupper(s[i]));
        }
        else if (s[i - 1] == ' ' && isalpha(s[i])) {
            t = 0;
            for (int j = 0; j < 10; j++) {
                if (strstr(&s[i], no[j]) == &s[i] && (s[i + strlen(no[j])] == ' ' || s[i + strlen(no[j])] == '\0')) t = 1;
            }
            if (t) continue;
            printf("%c", toupper(s[i]));
        }
    }
    return 0;
}