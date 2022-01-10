#include <stdio.h>

/*
문제 : 32자 이하의 소문자로 이루어진 문자열이 주어질 때, 쿼티 자판에서 왼손과 오른손이 바뀌는 횟수를 구한다.
왼손으로는 왼쪽 5개 자판을 치고, 오른손으로는 나머지 자판을 친다.

해결 방법 : 왼손으로 치는 자판인지 오른손으로 치는 자판인지 여부를 반환하는 함수를 만든 후,
모든 인접한 문자 쌍에 대해 치는 손이 다른 자판의 개수를 더하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : JAG 2011D A번
*/

char s[64];
char* left = "qwertasdfgzxcvb";

int isleft(char c) {
    for (int i = 0; i < 15; i++) {
        if (c == left[i]) return 1;
    }
    return 0;
}

int main(void) {
    int r;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        r = 0;
        for (int i = 1; s[i]; i++) {
            r += (isleft(s[i]) ^ isleft(s[i - 1]));
        }
        printf("%d\n", r);
    }
    return 0;
}