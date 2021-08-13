#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 80자 이하의 문자열이 주어질 때, 대소문자를 구별하지 않고 nemo라는 문자열이 포함되었는지 확인한다.

해결 방법 : tolower를 통해 모든 문자를 소문자로 바꾼 다음 strstr을 통해 nemo라는 문자열이 있는지 찾아보면 된다.

주요 알고리즘 : 문자열

출처 : PLU 2014N 4번
*/

char s[128];

int main(void) {
    int a, b;
    while (1) {
        fgets(s, 100, stdin);
        if (!strcmp(s, "EOI") || !strcmp(s, "EOI\n")) break;
        for (int i = 0; s[i]; i++) {
            s[i] = tolower(s[i]);
        }
        if (strstr(s, "nemo")) printf("Found\n");
        else printf("Missing\n");
    }
    return 0;
}