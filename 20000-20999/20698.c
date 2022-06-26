#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 점이 격자형태로 있다. 각 점의 좌표는 절댓값 10^6 이하의 정수이다.
이때, 정수인 임의의 점에 모든 점과의 맨해튼 거리를 최소로 하도록 할 때,
그 X, Y 방향의 거리를 구한다.

해결 방법 : X축과 Y축을 나누어 생각해보면 최적인 점의 좌표는 최솟값과 최댓값의 평균과 같다.
위치가 자연수가 되어야 하므로 각 방향의 거리는 ceil(거리 / 2)를 계산하면 된다.

주요 알고리즘 : 기하학

출처 : Jakarta 2020 M번
*/

int main(void) {
    int n, x, y, xl = INF, xh = -INF, yl = INF, yh = -INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x < xl) xl = x;
        if (x > xh) xh = x;
        if (y < yl) yl = y;
        if (y > yh) yh = y;
    }
    if (xl == INF) return 1;
    printf("%d %d", (xh - xl + 1) / 2, (yh - yl + 1) / 2);
    return 0;
}