#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 80자 이하 소문자로 이루어진 문자열이 주어질 때, 2개 연속한 모음의 개수가
가장 많은 문자열을 구한다. 모음은 'a,' 'e', 'i', 'o', 'u', 'y'이고 3개 이상 연속한 글자는 주어지지 않는다.
또한, 이러한 문자열은 유일하다.

해결 방법 : 연속한 모음의 개수를 구하고 이 개수가 최댓값보다 많아질 때 마다 갱신해가며 답을 찾으면 된다.

주요 알고리즘 : 구현, 문자열

출처 : VTH 2014 E번
*/

char s[128], r[128];

int main(void) {
    int n, c, b;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        b = -1;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            c = 0;
            for (int j = 1; s[j]; j++) {
                if (s[j] == s[j - 1] && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||
                    s[j] == 'o' || s[j] == 'u' || s[j] == 'y')) c++;
            }
            if (c > b) {
                strcpy(r, s);
                b = c;
            }
        }
        printf("%s\n", r);
    }
    return 0;
}
