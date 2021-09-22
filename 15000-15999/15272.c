#include <stdio.h>

/*
문제 : 30자 이하의 소문자로 이루어진 문자열이 주어질 때, s가 2회 연속으로 나오는 부분이 있는지 구한다.

해결 방법 : 2번째 문자부터 살펴보며 해당 문자와 이전 문자가 모두 s인 경우가 있는지 확인하면 된다.

주요 알고리즘 : 구현

출처 : Rocky 2017 A번
*/

char s[64];

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 1; s[i]; i++) {
        if (s[i] == 's' && s[i - 1] == 's') r = 1;
    }
    printf("%s", r ? "hiss" : "no hiss");
    return 0;
}