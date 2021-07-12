#include <stdio.h>

/*
문제 : 주어진 문자열의 주변을 :fan:으로 둘러싼다.

해결 방법 : 문자열을 입력받고 주변에 :fan:을 출력하면 된다.

주요 알고리즘 : 구현

출처 : 고려대 2017 B번
*/

char s[32];

int main(void) {
    scanf("%s", s);
    printf(":fan::fan::fan:\n:fan::%s::fan:\n:fan::fan::fan:", s);
    return 0;
}