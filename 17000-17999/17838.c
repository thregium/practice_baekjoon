#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10000 이하의 문자열이 주어질 때, "AABBABB" 형태를 만족하는지 구한다. 정확히 7글자로 이루어져야 하며,
2가지 문자로만 이루어져야 한다. 하지만 문자가 A와 B로만 이루어질 필요는 없다.

해결 방법 : 먼저 문자열의 길이가 7인지 확인하고 7이라면 각 문자들끼리 비교해서 해당 형태를 만족하는지 구하면 된다. 

주요 알고리즘 : 구현?

출처 : UNIST 1회 A번
*/

char s[10240];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        if (strlen(s) != 7) {
            printf("0\n");
            continue;
        }
        if (s[1] == s[0] && s[2] != s[0] && s[3] == s[2] && s[4] == s[0] && s[5] == s[2] && s[6] == s[2]) {
            printf("1\n");
        }
        else printf("0\n");
    }
    return 0;
}