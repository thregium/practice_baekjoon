#include <stdio.h>

/*
문제 : 임의의 크기를 갖는 원이 있고, 그 원을 두 직선이 4개의 영역으로 분할한다. 반시계방향으로 A, B, C, D의 영역이라 할 때,
A와 B를 구분짓는 선의 길이 AB, B와 C를 구분짓는 선의 길이 BC, C와 D를 구분짓는 선의 길이 CD가 순서대로 주어진다.
A와 D를 구분짓는 선의 길이를 구한다.

해결 방법 : AB * CD = BC * AD라는 공식을 이용한다.

주요 알고리즘 : 기하학

출처 : 플로우컵 1회 A번
*/

int main(void) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%.9lf", x * z / (double)y);
    return 0;
}