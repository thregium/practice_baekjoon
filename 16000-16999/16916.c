#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10^6 이하의 두 문자열이 주어질 때, 두 번째 문자열이 첫 번째 문자열의 부분 문자열인지 구한다.

해결 방법 : KMP 알고리즘을 이용한다.

주요 알고리즘 : 문자열, KMP
*/

char t[1048576], p[1048576];
int k[1048576], s[1048576];
int si = 0;

int main(void) {
    int f = 0;
    fgets(t, 1024000, stdin);
    fgets(p, 1024000, stdin);
    int n = strlen(t) - 1;
    int m = strlen(p) - 1;
    for (int i = 1; i < m; i++) {
        while (f > 0 && p[i] != p[f]) f = k[f - 1];
        if (p[f] == p[i]) k[i] = ++f;
    }
    f = 0;
    for (int i = 0; i < n; i++) {

        while (f > 0 && t[i] != p[f]) f = k[f - 1];

        if (t[i] == p[f]) {
            if (f == m - 1) {
                s[si++] = i - m + 2;
                f = k[f];
            }
            else f++;
        }
    }
    printf("%d", !!si);
    return 0;
}