#include <stdio.h>

/*
문제 : 주어진 80자 이하의 공백 없는 문자열을 압축한 결과를 출력한다.

해결 방법 : 다음 문자가 현재 문자와 다를 때 마다 현재까지 확인한 현재 문자와 같은 문자의 수를 출력해 나간다.

주요 알고리즘 : 구현, 문자열

출처 : CCC 2019 3번
*/

char s[128];

int main(void) {
    int t, c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        c = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] != s[i + 1]) {
                printf("%d %c ", c, s[i]);
                c = 1;
            }
            else c++;
        }
        printf("\n");
    }
    return 0;
}