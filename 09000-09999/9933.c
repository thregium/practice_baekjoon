#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 길이가 14 이하의 홀수인 문자열 가운데 뒤집은 문자열도 목록에 있는 문자열을 찾고, 해당하는 문자열의 길이와 가운데 문자를 구한다.

해결 방법 : 모든 문자열에 대해 자신을 뒤집은 문자열이 목록에 있는지 확인한다. 있다면 해당하는 문자열을 저장해두고 출력하면 된다.

주요 알고리즘 : 문자열, 브루트 포스, 구현

출처 : COCI 13/14#5 1번
*/

char s[128][16], rev[16];

int main(void) {
    int n, len, r = 1;
    char c = '\0';
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        len = strlen(s[i]);
        for (int j = 0, k = len - 1; j < len; j++, k--) {
            rev[j] = s[i][k];
        }
        rev[len] = '\0';
        for (int j = 0; j < n; j++) {
            if (strcmp(rev, s[j])) continue;
            c = rev[len >> 1];
            r = len;
        }
    }
    if (r < 2) return 1;
    printf("%d %c", r, c);
    return 0;
}