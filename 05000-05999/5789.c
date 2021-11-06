#include <stdio.h>
#include <string.h>

/*
문제 : 길이 1000 이하 짝수인 0, 1로 이루어진 문자열이 주어질 때, 이 문자열의 양 끝부터 확인하다가
마지막으로 만나는 두 문자가 같은지 다른지 확인한다.

해결 방법 : 그 문자는 가운데의 두 문자일 것이다. 전체 길이 번째와 그 앞의 문자를 비교해보면 된다.

주요 알고리즘 : 구현?

출처 : SPR 2012 A번
*/

char s[1024];

int main(void) {
    int n, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        l = strlen(s);
        if (s[l >> 1] == s[(l >> 1) - 1]) printf("Do-it\n");
        else printf("Do-it-Not\n");
    }
    return 0;
}