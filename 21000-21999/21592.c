#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 길이 100 이하 소문자로 이루어진 문자열들이 주어진다.
이 문자열들에 대해 모든 문자열에 포함되는 가장 긴 부분 문자열의 길이를 구한다.

해결 방법 : 문자열의 길이와 개수가 적으므로 첫 번째 문자열의 모든 부분 문자열들을 만들어 보면서
그 중 모든 문자열에 속하는 가장 긴 문자열의 길이를 구하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : NADC 2021 H번
*/

char s[1024][128], t[128];

int main(void) {
    int n, l, res = 0, ok;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    l = strlen(s[0]);
    for (int i = 0; i < l; i++) {
        for (int j = i; j < l; j++) {
            for (int k = i; k <= j; k++) t[k - i] = s[0][k];
            t[j - i + 1] = '\0';
            ok = 1;
            for (int k = 0; k < n; k++) {
                if (!strstr(s[k], t)) ok = 0;
            }
            if (ok && j - i + 1 > res) res = j - i + 1;
        }
    }
    printf("%d", res);
    return 0;
}