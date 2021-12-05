#include <stdio.h>

/*
문제 : N(N <= 1000)개의 직사각형의 좌표(<= 10000, 음이 아닌 정수)가 주어질 때, 모든 직사각형이 겹치는 부분의 넓이를 구한다.

해결 방법 : 직사각형의 X좌표와 Y좌표의 낮은 쪽의 가장 높은 값과 높은 쪽의 가장 낮은 값들을 각각 구한다.
만약 높은 쪽과 낮은 쪽의 범위가 겹치지 않는다면 답은 0이고, 그 외에는 두 구간의 차의 곱이 답이 된다.

주요 알고리즘 : 수학, 기하학

출처 : NOIS 2007 2번
*/

int main(void) {
    int n, x1, y1, x2, y2, xl = 12345, xh = -1, yl = 12345, yh = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
        if (x1 > xh) xh = x1;
        if (x2 < xl) xl = x2;
        if (y1 > yh) yh = y1;
        if (y2 < yl) yl = y2;
    }
    if (xh > xl || yh > yl) printf("0");
    else printf("%d", (xl - xh) * (yl - yh));
    return 0;
}