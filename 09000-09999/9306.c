#include <stdio.h>

/*
문제 : 주어진 이름을 반대 순서로 출력한다.

해결 방법 : 문자열 2개를 입력받고 반대 순서로 출력하면 된다.

주요 알고리즘 : 구현

출처 : UVaH 2012 P번
*/

char first[32], last[32];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s%s", first, last);
        printf("Case %d: %s, %s\n", tt, last, first);
    }
    return 0;
}