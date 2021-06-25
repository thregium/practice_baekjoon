#include <stdio.h>
#include <math.h>

/*
문제 : 주어진 점과 직사각형(XY축과 평행한)이 주어질 때, 점과 직사각형의 거리를 구한다. 단, 점은 직사각형의 바깥에 있다.

해결 방법 : 직사각형의 선분을 연장하면 좌표평면이 9개(직사각형 내부를 제외하면 8개)로 나누어 진다.
경우를 나누어 각각에 대한 값을 구한다. 대각선 방향이라면 피타고라서 정리를 이용해 꼭짓점과의 거리를 구하고,
변 방향이라면 해당 변과의 x좌표 또는 y좌표 차이를 구하면 된다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : PacNW 2018 G/T번 // MidC 2018 F번 // SEUSA 2018D2 B번
*/

double getdist(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(void) {
    int x, y, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);
    if (x < x1 && y < y1) printf("%lf", getdist(x, y, x1, y1));
    else if (x < x1 && y > y2) printf("%lf", getdist(x, y, x1, y2));
    else if (x > x2 && y < y1) printf("%lf", getdist(x, y, x2, y1));
    else if (x > x2 && y > y2) printf("%lf", getdist(x, y, x2, y2));
    else if (x < x1) printf("%d", x1 - x);
    else if (x > x2) printf("%d", x - x2);
    else if (y < y1) printf("%d", y1 - y);
    else if (y > y2) printf("%d", y - y2);
    return 0;
}