#include <stdio.h>

/*
문제 : N(2 <= N <= 50)개의 쥐가 직선형으로 움직인다. 이때, 좌표축에 평행한 정사각형 형태의 울타리로
모든 쥐를 가둘 수 있는 가장 작은 한 변의 길이 L을 구한다.
쥐의 좌표와 이동 속도는 절댓값 1000 이하의 정수다.

해결 방법 : 시간 T에 따른 울타리 영역의 크기는 아래로 볼록한 개형을 그리기 때문에 삼분 탐색이 가능하다.
따라서, 삼분 탐색을 통해 영역이 최소가 되는 지점을 찾으면 된다. 최댓값은 2000으로 두면 된다.

주요 알고리즘 : 기하학, 삼분 탐색

출처 : SRM 426 D1 2번
*/

double rat[64][4];

double getsize(int n, double tm) {
    double xl = 1E9, xh = -1E9, yl = 1E9, yh = -1E9, x, y;
    for (int i = 0; i < n; i++) {
        x = rat[i][0] + rat[i][2] * tm;
        y = rat[i][1] + rat[i][3] * tm;
        if (x < xl) xl = x;
        if (x > xh) xh = x;
        if (y < yl) yl = y;
        if (y > yh) yh = y;
    }
    return xh - xl > yh - yl ? xh - xl : yh - yl;
}

int main(void) {
    int n;
    double lo = 0.0, hi = 2000.0, mid1, mid2, res = 2000.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf", &rat[i][0], &rat[i][1], &rat[i][2], &rat[i][3]);
    }

    for (int i = 0; i < 0401; i++) {
        mid1 = (lo * 2 + hi) / 3.0;
        mid2 = (lo + hi * 2) / 3.0;
        
        if (getsize(n, mid1) < getsize(n, mid2)) hi = mid2;
        else lo = mid1;
    }
    printf("%.15f", getsize(n, lo));
    return 0;
}