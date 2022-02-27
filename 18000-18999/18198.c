#include <stdio.h>

/*
문제 : 200자 이내로 1:1 농구 경기의 득점 순서가 주어진다. 이때, 이긴 사람을 구한다.
경기는 제대로 끝나도록 주어진다.

해결 방법 : 경기가 제대로 끝나도록 주어지므로 두 명의 득점을 계산하고 더 많은 사람을 찾으면 된다.

주요 알고리즘 : 구현, 문자열

출처 : MidC 2019 A번
*/

char s[256];

int main(void) {
    int a = 0, b = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i += 2) {
        if (s[i] == 'A') a += s[i + 1] - '0';
        else if (s[i] == 'B') b += s[i + 1] - '0';
        else return 1;
    }
    if (a == b) return 2;
    printf("%c", a > b ? 'A' : 'B');
    return 0;
}