#include <stdio.h>

/*
문제 : B(B <= 1000) * 8 길이의 I와 O로 이루어진 문자열이 주어질 때, 이 문자열의 I를 1, O로 해석하고
8글자씩 아스키 코드로 변환한 문자열을 구한다.

해결 방법 : 각 문자열을 8자 단위로 자르고 8자리의 변환한 수를 구한다. 이 수의 아스키 값을 출력해가면 된다.

주요 알고리즘 : 문자열, 구현, 수학

출처 : GCJ 2015W A1번
*/

char s[8192];

int main(void) {
    int t, b, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &b);
        scanf("%s", s);
        printf("Case #%d: ", tt);
        for (int i = 0; i < b; i++) {
            c = 0;
            for (int j = 0; j < 8; j++) {
                c <<= 1;
                c += (s[i * 8 + j] == 'I');
            }
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}