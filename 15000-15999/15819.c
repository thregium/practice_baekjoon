#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 길이 20 이하인 문자열 가운데 사전순으로 I번째인 것을 찾는다.

해결 방법 : 문자열들을 정렬시킨 후, I - 1번 문자열을 출력하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : 아주대 2018P B번
*/

char s[128][32];

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 32, strcmp);
    printf("%s", s[l - 1]);
    return 0;
}