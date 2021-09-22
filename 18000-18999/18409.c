#include <stdio.h>

/*
문제 : 길이 N(N <= 50)의 소문자로 이루어진 문자열에서 모음이 몇 개 있는지 구한다.

해결 방법 : 각 문자들을 확인하며 a, e, i, o, u 의 개수를 세면 된다.

주요 알고리즘 : 구현

출처 : JOI 2020예1 1-2번
*/

char s[64];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') r++;
    }
    printf("%d", r);
    return 0;
}