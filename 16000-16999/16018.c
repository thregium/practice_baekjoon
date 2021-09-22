#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 문자열 2개가 주어질 때, 양쪽 문자열에서 모두 C인 문자의 개수를 구한다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현

출처 : CCC 2018 J2번
*/

char ye[128], to[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s%s", ye, to);
    for (int i = 0; i < n; i++) {
        r += ((ye[i] == 'C') && (to[i] == 'C'));
    }
    printf("%d", r);
    return 0;
}