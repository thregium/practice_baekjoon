#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : N(N <= 1000)개의 대소문자로 이루어진 30자 이하의 문자열들이 주어질 때,
대소문자를 무시하고 pink 또는 rose가 포함된 문자열의 개수를 구한다.

해결 방법 : 주어진 문자열의 모든 문자에 tolower()를 한 다음, strstr 함수를 통해 pink 또는 rose가 있는
문자열의 개수를 세면 된다.

주요 알고리즘 : 문자열

출처 : SwCC 2021L A번
*/

char s[32];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) s[j] = tolower(s[j]);
        if (strstr(s, "pink") || strstr(s, "rose")) r++;
    }
    if (r) printf("%d", r);
    else printf("I must watch Star Wars with my daughter");
    return 0;
}