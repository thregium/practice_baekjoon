#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 주어진 N(N <= 1000)개의 20자 이하인 문자열들을 대소문자 구별 없는 상태에서 사전순으로 가장 빠른 문자열을 찾는다.

해결 방법 : 각 문자열을 전부 소문자로 만든 것과 원래 문자열을 쌍으로 만든 뒤, 소문자 문자열을 기준으로 정렬한다.
그 다음 처음 오는 원래 문자열을 찾으면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : NZPC 2005 A번
*/

char s[1024][64];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i] + 32);
            for (int j = 0; s[i][j + 32]; j++) {
                s[i][j] = tolower(s[i][j + 32]);
            }
        }
        qsort(s, n, sizeof(char) * 64, strcmp);
        printf("%s\n", s[0] + 32);
    }
    return 0;
}