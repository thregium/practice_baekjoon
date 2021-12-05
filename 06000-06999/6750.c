#include <stdio.h>

/*
문제 : 30자 이하의 대문자로 이루어진 문자열이 주어질 때, 180도 돌려도 그대로인 문자로만 이루어져 있는지 구한다.

해결 방법 : 그러한 문자는 I, O, S, H, Z, X, N이 있다. 그러한 문자로만 이루어져 있는지 구하면 된다.

주요 알고리즘 : 구현

출처 : CCC 2013J 2번
*/

char s[64];

int main(void) {
    int r = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] != 'I' && s[i] != 'O' && s[i] != 'S' && s[i] != 'H' && s[i] != 'Z' && s[i] != 'X' && s[i] != 'N') r = 0;
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}