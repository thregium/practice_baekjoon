#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 길이 1000 이하의 문자열이 주어질 때, 이 알파벳의 자음과 모음의 개수를 구한다.

해결 방법 : 문자열의 모든 문자를 확인하며 알파벳인 것을 찾는다. 알파벳이라면 이것이 모음인지 확인하고 아니라면 자음일 것이다.
이제 확인한 모음과 자음을 세면 된다.

주요 알고리즘 : 구현

출처 : CCPC 2015 D2B번
*/

char sen[1024];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

int main(void) {
    int s, c, v;
    scanf("%d\n", &s);
    for (int i = 0; i < s; i++) {
        fgets(sen, 1013, stdin);
        c = 0, v = 0;
        for (int j = 0; sen[j]; j++) {
            if (isalpha(sen[j])) {
                if (isvowel(tolower(sen[j]))) v++;
                else c++;
            }
        }
        printf("%d %d\n", c, v);
    }
    return 0;
}