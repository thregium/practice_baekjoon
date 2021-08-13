#include <stdio.h>

/*
문제 : 주어진 입력이 몇 줄인지 구한다.

해결 방법 : fgets를 통해 줄 단위로 입력받을 수 있다. EOF가 나오는 경우 0을 반환하므로 while문을 사용하면 된다.

주요 알고리즘 : 문자열?, 애드 혹?

출처 : Rocky 2012 P번
*/

char s[128];

int main(void) {
    int r = 0;
    while (fgets(s, 120, stdin)) r++;
    printf("%d", r);
    return 0;
}