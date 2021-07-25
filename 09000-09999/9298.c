#include <stdio.h>

/*
문제 : N(N <= 100)개의 점을 포함하는 가장 작은 좌표평면에 평행한 방향의 직사각형의 넓이와 둘레를 구한다.

해결 방법 : 각 점들 중 가장 x좌표가 작은 점부터 x좌표가 큰 점까지의 거리가 가로의 길이가 되고
y좌표가 가장 작은 점부터 큰 점까지의 거리가 세로의 길이가 된다. 이 값들을 이용해 넓이와 둘레를 구하면 된다.

주요 알고리즘 : 기하학

출처 : UVa 2012 C번
*/

int main(void) {
    int t, n;
    double x, y, xl, xh, yl, yh;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        xl = 1024, xh = -1024, yl = 1024, yh = -1024;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            if (x < xl) xl = x;
            if (x > xh) xh = x;
            if (y < yl) yl = y;
            if (y > yl) yh = y;
        }
        printf("Case %d: Area %.16f, Perimeter %.16f\n", tt, (xh - xl) * (yh - yl), 2 * ((xh - xl) + (yh - yl)));
    }
    return 0;
}