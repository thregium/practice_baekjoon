#include <stdio.h>

/*
문제 : A * 7과 P * 13 중 더 큰 것이 무엇인지 구한다.

해결 방법 : 문제에 쓰인대로 구현한다.

주요 알고리즘 : 구현?

출처 : SwOI 2021Q A번
*/

int main(void) {
    int a, p;
    scanf("%d %d", &a, &p);
    if (a * 7 < p * 13) printf("Petra");
    else if (a * 7 == p * 13) printf("lika");
    else printf("Axel");
    return 0;
}