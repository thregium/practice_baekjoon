#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 문자열(소문자, 20자 이하)이 주어질 때, 서로 다른 문자열의 개수를 구한다.

해결 방법 : 문자열들을 입력받고 정렬한 다음, 첫 번째 문자열부터 문자열의 개수를 세되,
만약 이전 문자열이 지금 문자열과 같다면 세지 않는다. 그 결과 센 문자열의 개수가 답이 된다.

주요 알고리즘 : 문자열, 정렬

출처 : Rocky 2015 J번
*/

char s[128][32];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
        }
        qsort(s, n, sizeof(char) * 32, strcmp);
        r = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && !strcmp(s[i], s[i - 1])) continue;
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}