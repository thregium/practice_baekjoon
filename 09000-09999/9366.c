#include <stdio.h>

/*
문제 : 삼각형의 세 변의 길이가 주어질 때, 이 삼각형의 유형을 구한다. 단, 삼각형이 되지 않는 경우도 따로 구한다.

해결 방법 : 한 변이 나머지 두 변의 합 이상이면 삼각형이 되지 않는다. 세 변이 모두 같으면 정삼각형이고,
두 변이 같으면 이등변, 아니면 부등변삼각형이다.

주요 알고리즘 : 구현, 기하학

출처 : LCPC 2011 I번
*/

int main(void) {
    int t, a, b, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", tt);
        if (a >= b + c || b >= a + c || c >= a + b) printf("invalid!\n");
        else if (a == b && a == c) printf("equilateral\n");
        else if (a == b || a == c || b == c) printf("isosceles\n");
        else printf("scalene\n");
    }
    return 0;
}