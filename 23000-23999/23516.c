#include <stdio.h>
#include <string.h>

/*
문제 : 50자리 이하의 두 소문자로 이루어진 문자열이 주어질 때, 두 문자열의 공약수가 되는 문자열(해당 문자열을 반복하여
두 문자열을 모두 만들 수 있는 문자열) 가운데 가장 짧은 것을 구한다. 없다면 No solution을 출력한다.

해결 방법 : 길이 1부터 짧은 문자열의 길이까지 공약수가 되는 지 구하고, 되는 것이 나오면 그 문자열을 출력하면 된다.
공약수인지 여부는 해당 문자열을 반복하는지를 두 문자열에 대해 각각 모든 문자에 대해 확인하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : OC 18/19_17 F번
*/

char s[64], t[64];

int main(void) {
    int sl, tl, tmp, r = 0;
    scanf("%s%s", s, t);
    sl = strlen(s);
    tl = strlen(t);
    for (int i = 1; i <= sl; i++) {
        if (sl % i || tl % i) continue;
        tmp = 1;
        for (int j = 0; s[j + i]; j++) {
            if (s[j] != s[j + i]) {
                tmp = 0;
                break;
            }
        }
        if (!tmp) continue;
        for (int j = 0; t[j + i]; j++) {
            if (t[j] != t[j + i]) {
                tmp = 0;
                break;
            }
        }
        for (int j = 0; s[j] && t[j]; j++) {
            if (s[j] != t[j]) {
                tmp = 0;
                break;
            }
        }
        if (tmp) {
            r = i;
            break;
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%c", s[i]);
    }
    if (r == 0) printf("No solution");
    return 0;
}