#include <stdio.h>

/*
문제 : 두 길이가 같은 이진수 문자열(100자 이하)이 주어질 때, 서로 다른 자리의 개수를 구한다.

해결 방법 : 문자열을 시작부터 끝까지 보면서 서로 다른 자리의 개수를 세면 된다.

주요 알고리즘 : 구현

출처 : CERC 2007 PD번
*/

char s1[128], s2[128];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = 0;
        scanf("%s%s", s1, s2);
        for (int i = 0; s1[i]; i++) {
            if (s1[i] != s2[i]) r++;
        }
        printf("Hamming distance is %d.\n", r);
    }
    return 0;
}