#include <stdio.h>
#include <string.h>

/*
문제 : 길이 30 이하의 소문자로 이루어진 문자열이 주어질 때, 한 글자를 지워 회문을 만들 수 있는지 구하고,
가능하다면 그 중 가장 앞의 글자를 지우는 경우의 문자열을 구한다.

해결 방법 : 문자열의 길이가 짧으므로 모든 경우를 직접 해보면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : NZPC 2016 D번
*/

char s[32], r[32];

int main(void) {
    int res, tmp;
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "#")) break;
        res = 0;
        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < i; j++) r[j] = s[j];
            for (int j = i + 1; s[j]; j++) r[j - 1] = s[j];
            tmp = 1;
            r[strlen(s) - 1] = '\0';
            for (int j = 0, k = strlen(r) - 1; j < k; j++, k--) {
                if (r[j] != r[k]) tmp = 0;
            }
            if (tmp) {
                res = 1;
                printf("%s\n", r);
                break;
            }
        }
        if (!res) printf("not possible\n");
    }
    return 0;
}