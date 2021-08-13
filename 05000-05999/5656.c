#include <stdio.h>
#include <string.h>

/*
문제 : 두 정수 A와 B의 관계식이 주어질 때, 이 관계식이 참인지 구한다.

해결 방법 : 어떤 관계식인지 확인한 다음 참인지 찾아보면 된다.

주요 알고리즘 : 구현, 문자열

출처 : Phuket 2009 E번
*/

char s[4];

int main(void) {
    int a, b, r = 0;
    for (int i = 1;; i++) {
        scanf("%d %s %d", &a, s, &b);
        if (!strcmp(s, ">")) r = (a > b);
        else if (!strcmp(s, ">=")) r = (a >= b);
        else if (!strcmp(s, "<")) r = (a < b);
        else if (!strcmp(s, "<=")) r = (a <= b);
        else if (!strcmp(s, "==")) r = (a == b);
        else if (!strcmp(s, "!=")) r = (a != b);
        else break;
        printf("Case %d: ", i);
        printf("%s\n", r ? "true" : "false");
    }
    return 0;
}