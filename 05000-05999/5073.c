#include <stdio.h>

/*
문제 : 주어진 세 변의 길이를 갖는 삼각형이 있을 수 있는지 확인하고 가능하다면
정삼각형인지 이등변삼각형인지 부등변삼각형인지 구한다.

해결 방법 : 먼저, 한 변의 길이가 다른 두 변의 길이 이상이라면 삼각형을 만들 수 없다.
그렇지 않다면 모든 변이 동일한지 확인하고(정삼각형), 같은 변이 하나라도 있는지(이등변삼각형) 확인하면 된다.

주요 알고리즘 : 기하학

출처 : NZPC 2012 B번
*/

int main(void) {
    int t, a, b, c;
    for (;;) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) break;
        if (a >= b + c || b >= a + c || c >= a + b) printf("Invalid\n");
        else if (a == b && a == c) printf("Equilateral\n");
        else if (a == b || a == c || b == c) printf("Isosceles\n");
        else printf("Scalene\n");
    }
    return 0;
}