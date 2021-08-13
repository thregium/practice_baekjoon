#include <stdio.h>

/*
문제 : 주어진 N(N <= 20)개의 점들을 전부 포함하며 좌표평면에 평행한 가장 작은 정사각형의 넓이를 구한다.

해결 방법 : 모든 점들 중 X좌표의 최솟값과 최댓값, Y좌표의 최솟값과 최댓값을 구한다. 답이 되는 정사각형의 한 변의 길이는
Y좌표의 최댓값 - 최솟값 또는 X좌표의 최댓값 - 최솟값 중 작은 것이고, 넓이는 그의 제곱이다.

주요 알고리즘 : 기하학

출처 : COCI 14/15#1 2번
*/

int main(void) {
    int n, x, y, xl = 999, xh = -999, yl = 999, yh = -999;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x < xl) xl = x;
        if (x > xh) xh = x;
        if (y < yl) yl = y;
        if (y > yh) yh = y;
    }
    if (yh - yl > xh - xl) printf("%d", (yh - yl) * (yh - yl));
    else printf("%d", (xh - xl) * (xh - xl));
    return 0;
}