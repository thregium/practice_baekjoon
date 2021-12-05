#include <stdio.h>
#include <math.h>

/*
문제 : (0, 0)에서 (X, Y)(X, Y <= 1000)로 이동하는 최단 시간을 구한다. 1초에 1씩 움직이는 방법과 T초에 D(T, D <= 10000)씩
움직이는 방법이 있다. 단, 후자인 경우에는 반드시 한번에 D씩 움직여야 하고 중간에 멈출 수 없다.

해결 방법 : 만약 D가 (X, Y)까지의 거리보다 먼 경우에는 다른 먼 곳을 찍고 돌아오는 방법과, (X, Y) 방향으로 멀리 움직였다가
걸어서 돌아오는 방법, 그대로 걸어가는 방법 3가지 종류가 있다. 각각의 거리를 구하고 이 중 가장 작은 것을 구하면 된다.
그 외의 경우에는 1번 더 움직여서 도착지까지 워프하는 방법과 가장 가까운 곳까지 간 후 걸어가는 방법,
그대로 걸어가는 방법의 3가지이고, 이 경우에도 마찬가지로 각각의 거리 가운데 가장 작은 것을 구하면 된다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : SRM 318 D1A / D2B
*/

double small(double a, double b) {
    return a < b ? a : b;
}

double getdist(int x, int y) {
    return sqrt(x * x + y * y);
}

int main(void) {
    int x, y, d, t, c;
    double l = 0.0, r1, r2;
    scanf("%d %d %d %d", &x, &y, &d, &t);
    l = getdist(x, y);
    c = (int)(l / d);
    if (c == 0) {
        r1 = 2 * t;
        r2 = t + d - l;
        printf("%.16f", small(l, small(r1, r2)));
    }
    else {
        r1 = (c + 1) * t;
        r2 = c * t + l - c * d;
        printf("%.16f", small(l, small(r1, r2)));
    }
    return 0;
}