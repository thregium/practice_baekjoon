#include <stdio.h>

/*
문제 : 각 회원들을 청소년부와 성인부로 나눈다. 성인부로 가는 기준은 나이가 17세보다 많거나 몸무게가 80kg 이상일 때이다.

해결 방법 : 나이가 17세를 넘거나 몸무게가 80kg 이상인지 확인하면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2005 B번
*/

char s[16];

int main(void) {
    int a, w;
    while (1) {
        scanf("%s %d %d", s, &a, &w);
        if (s[0] == '#') break;
        if (a > 17 || w >= 80) printf("%s Senior\n", s);
        else printf("%s Junior\n", s);
    }
    return 0;
}