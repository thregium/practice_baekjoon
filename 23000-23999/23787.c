#include <stdio.h>

/*
문제 : '1'과 '0'으로 이루어진 길이 300000 이하의 문자열이 주어질 때, '1' 또는 가장자리에서 가장 멀리 떨어진
'0'의 거리를 구한다.

해결 방법 : 0이 연속한 가장 긴 구간의 길이에서 한가운데 있는 0이 가장 멀리 떨어져 있다.
떨어진 거리는 길이 / 2를 올림한 값과 같다.

주요 알고리즘 : 구현, 문자열

출처 : CTU 2021 R번
*/

char s[327680];

int main(void) {
    int con = 0, best = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') con++;
        else con = 0;
        if (con > best) best = con;
    }
    printf("%d", (best + 1) / 2);
    return 0;
}