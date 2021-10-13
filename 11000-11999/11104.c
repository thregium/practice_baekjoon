#include <stdio.h>
#include <stdlib.h>

/*
문제 : 24자리의 이진법 문자열 N(N <= 1000)개에 대해 각각을 십진법으로 바꾼 결과를 출력한다.

해결 방법 : strtoll 함수를 이용한다.

주요 알고리즘 : 구현

출처 : IDI 2007 G번
*/

char s[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%lld\n", strtoll(s, NULL, 2));
    }
    return 0;
}