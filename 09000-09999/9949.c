#include <stdio.h>
#include <ctype.h>

/*
문제 : N(N <= 100)개의 문자열에 대해 서로 다른 두 소문자가 주어질 때, 해당 알파벳 '_'로 바꾸어 출력한다.
대문자도 마찬가지로 '_'로 바꾸어야 한다. 각 문자열의 길이는 255 이하로 주어진다.

해결 방법 : 두 문자를 입력받은 후, 각 문자열들을 입력받는다. 각 문자열들의 문자열을 확인하며 tolower()함수를 적용한
해당 문자가 두 문자 가운데 있는지 확인한다. 있다면 '_'를 입력하고, 없다면 그대로 원래 문자를 출력한다.
이를 반복해 모든 문자를 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NZPC 2007 C번
*/

char s[320];

int main(void) {
    int n;
    char a, b;
    for (int tt = 1;; tt++) {
        scanf(" %c %c", &a, &b);
        if (a == '#') break;
        scanf("%d", &n);
        printf("Case %d\n", tt);
        for (int i = 0; i < n; i++) {
            fgets(s, 300, stdin);
            if (s[0] == '\n') {
                i--;
                continue;
            }
            for (int j = 0; s[j]; j++) {
                printf("%c", (tolower(s[j]) == a || tolower(s[j]) == b) ? '_' : s[j]);
            }
        }
        printf("\n");
    }
    return 0;
}