#include <stdio.h>
#include <stdlib.h>

/*
문제 : 무한히 넓은 격자평면상의 두 점 (a, b)와 (c, d) 사이에 격자선만을 따라가는 길이 T(T <= 10000)인 경로가 있는 지 구한다.
각 점의 좌표는 += 1000 이하의 정수이다.

해결 방법 : 만약 두 점 사이의 맨해튼 거리가 T보다 길다면 당연히 불가능하다.
그 외의 경우에는 맨해튼 거리와 길이의 홀짝성을 비교한다. 홀짝성이 같은 경우 가능하고 다른 경우 불가능하다.
(홀수 사이클이 없기 때문)

주요 알고리즘 : 수학

출처 : CCC 2017J 3번
*/

int main(void) {
    int a, b, c, d, td, t;
    scanf("%d %d%d %d%d", &a, &b, &c, &d, &t);
    td = abs(a - c) + abs(b - d);
    if (td > t) printf("N");
    else printf("%c", ((t - td) & 1) ? 'N' : 'Y');
    return 0;
}