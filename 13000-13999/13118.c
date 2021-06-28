#include <stdio.h>

/*
문제 : X축 위의 점 4개와 원 하나가 주어질 때, 원이 수직선에 닿게 되는 점을 구한다.
단, 수직선에 닿는 즉시 멈추고, 네 점 모두와 닿지 않을 수도 있다.

해결 방법 : 원의 중심과 같은 X좌표를 갖는 점에 닿게 된다.

주요 알고리즘 : 구현, 기하학?

출처 : CoderH 2016R2 A번
*/

int main(void) {
    int p1, p2, p3, p4, x, y, r;
    scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
    scanf("%d %d %d", &x, &y, &r);
    if (x == p1) printf("1");
    else if (x == p2) printf("2");
    else if (x == p3) printf("3");
    else if (x == p4) printf("4");
    else printf("0");
    return 0;
}