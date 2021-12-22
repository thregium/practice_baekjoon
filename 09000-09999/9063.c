#include <stdio.h>
#define INF 103000

/*
문제 : 좌표평면상에 N(1 <= N <= 100000)개의 정수 점의 위치(|| <= 10000)가 주어질 때,
모든 점을 포함하는 좌표축에 평행한 가장 작은 직사각형의 넓이를 구한다.

해결 방법 : X와 Y좌표의 최소, 최댓값을 들고 있다가, 점이 나올 때 마다 각 값을 갱신한다.
마지막의 (X좌표 최대 - 최소) * (Y좌표 최대 - 최소)의 값이 답이 된다.

주요 알고리즘 : 기하학

출처 : Seoul 2006I A번
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
    printf("%d", (xh - xl) * (yh - yl));
    return 0;
}