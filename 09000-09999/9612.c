#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 문자열(소문자, 20자) 가운데 가장 많이 나온 것 중 가장 사전 순으로 늦은 것과
그 등장 횟수를 구한다.

해결 방법 : 문자열을 사전순으로 정렬한 다음, 인접한 것의 등장 횟수를 통해 등장 횟수를 찾는다.
동점인 경우 나중에 나온 것이 우선이다.

주요 알고리즘 : 문자열, 정렬

출처 : Phuket 2013 PD번
*/

char s[1024][32], best[32];

int main(void) {
    int n, r = 1, x = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 32, strcmp);
    strcpy(best, s[0]);
    for (int i = 1; i < n; i++) {
        if (strcmp(s[i], s[i - 1])) x = 1;
        else {
            x++;
            if (x >= r) {
                r = x;
                strcpy(best, s[i]);
            }
        }
    }
    printf("%s %d", best, r);
    return 0;
}
