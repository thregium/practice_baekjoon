#include <stdio.h>

/*
문제 : 길이 50 이하의 대문자로 이루어진 문자열이 주어질 때, 각 문자의 다음 문자로 이루어진 문자열을 출력한다.
Z의 다음 문자는 A로 생각한다.

해결 방법 : 문자열을 확인하며 Z가 나오면 A를 출력하고 그 외에는 아스키 값에 1을 더한 값을 출력하면 된다.

주요 알고리즘 : 구현

출처 : SWERC 1997 PA번
*/

char s[64];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        printf("String #%d\n", i);
        for (int j = 0; s[j]; j++) {
            if (s[j] == 'Z') printf("A");
            else printf("%c", s[j] + 1);
        }
        printf("\n\n");
    }
    return 0;
}