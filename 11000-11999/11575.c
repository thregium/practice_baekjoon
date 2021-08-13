#include <stdio.h>

/*
문제 : 100만자 이하의 대문자로만 이루어진 문자열을 아핀 암호를 통해 암호화시킨 문자열을 구한다.
아핀 문자열은 x번째 문자를 (a * x + b) mod 26번째 문자로 바꾸는 방식이다. 이때 a는 26과 서로소이다.

해결 방법 : 주어진 방식대로 암호화시킨다. 각 문자가 몇 번째인지는 'A'를 빼면 알 수 있고, 'A'를 다시 더하면 각 문자가 된다.

주요 알고리즘 : 구현, 문자열

출처 : 인하대 2015 A번
*/

char s[1048576];

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            printf("%c", (a * (s[i] - 'A') + b) % 26 + 'A');
        }
        printf("\n");
    }
    return 0;
}