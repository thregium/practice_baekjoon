#include <stdio.h>
#include <string.h>

/*
문제 : 100자 이하의 문자열이 주어질 때, 이 문자열의 모든 팰린드롬인 부분 문자열이 홀수 길이인지 구한다.

해결 방법 : 반대로 생각하면 짝수 길이의 팰린드롬인 부분 문자열이 있는지 구하는 문제가 된다.
따라서, 모든 짝수 길이의 구간에 대해 해당 구간의 부분 문자열이 팰린드롬인지 확인하고 그러한 것이 있다면
조건에 맞지 않는 것이고, 없다면 조건에 맞는 것이다.

주요 알고리즘 : 브루트 포스, 문자열

출처 : PacNW 2017 A/N번
*/

char s[128];

int main(void) {
    int t, len, r = 0;
    scanf("%s", s);
    len = strlen(s);
    for (int i = 2; i < len; i += 2) {
        for (int j = 0; j + i - 1 < len; j++) {
            t = 0;
            for (int st = j, ed = j + i - 1; st < ed; st++, ed--) {
                if (s[st] != s[ed]) {
                    t = 1;
                    break;
                }
            }
            if (!t) r = 1;
        }
    }
    if (r) printf("Or not.");
    else printf("Odd.");
    return 0;
}