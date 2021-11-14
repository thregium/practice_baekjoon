#include <stdio.h>

/*
문제 : 정사각형의 세 점이 주어질 때, 나머지 한 점의 위치를 구한다.

해결 방법 : 내적을 이용해 직각인 각을 확인하고, 그 각에 대해 마주보는 점을 구하면 된다.

주요 알고리즘 : 기하학

출처 : BAPC 2016P C번
*/

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d%d %d%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if ((x1 - x3) * (x2 - x3) == -(y1 - y3) * (y2 - y3)) printf("%d %d", x1 + x2 - x3, y1 + y2 - y3);
    else if ((x1 - x2) * (x3 - x2) == -(y1 - y2) * (y3 - y2)) printf("%d %d", x1 + x3 - x2, y1 + y3 - y2);
    else if ((x2 - x1) * (x3 - x1) == -(y2 - y1) * (y3 - y1)) printf("%d %d", x2 + x3 - x1, y2 + y3 - y1);
    else return 1;
    return 0;
}