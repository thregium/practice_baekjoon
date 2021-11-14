#include <stdio.h>

/*
문제 : 평면상에 세 점이 주어질 때, 세 점이 직선상에 있는지 구한다. 세 점의 좌표는 1 이상 1000 이하의 정수로 구성된다.

해결 방법 : CCW 알고리즘을 이용한다.

주요 알고리즘 : 기하학, CCW
*/

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (ccw(x1, y1, x2, y2, x3, y3)) printf("WINNER WINNER CHICKEN DINNER!");
    else printf("WHERE IS MY CHICKEN?");
    return 0;
}