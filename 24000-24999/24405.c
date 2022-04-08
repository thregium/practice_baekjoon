#include <stdio.h>
#include <string.h>

/*
문제 : 길이 100 이하의 '|'과 '()', '|'로 이루어진 문자열에서 '()'의 왼쪽과 오른쪽의
'|' 개수가 같은 지 구한다. '()'는 정확히 1개 있다.

해결 방법 : 첫 '('가 나올 때 까지 왼쪽의 '|' 개수를 세고, 다시 오른쪽부터 확인하며 ')'가 나올 때 까지
오른쪽의 '|' 개수를 센다. 그 다음 둘의 개수를 비교하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NAQ 2021 E번
*/

char s[128];

int main(void) {
    int l = 0, r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') break;
        else l++;
    }
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ')') break;
        else r++;
    }
    if (l == r) printf("correct");
    else printf("fix");
    return 0;
}