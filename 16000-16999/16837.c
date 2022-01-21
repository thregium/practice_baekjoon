#include <stdio.h>
#include <math.h>

/*
문제 : 크기 1의 격자로 된 평면상의 격자선 위 두 점 사이 유클리드 거리가 D(0 < D <= 10, 실수)인 지점 가운데
가장 두 점 사이 맨해튼 거리가 먼 경우의 맨해튼 거리를 구한다.

해결 방법 : 맨해튼 거리가 멀어지는 경우의 후보로는 1. 대각선 방향의 두 점인 경우,
2. 1 * floor(D) 크기의 직사각형의 1인 양쪽 변에 두 점이 있는 경우 두 가지이다.
1의 거리는 D * sqrt(2)이고, 2의 거리는 floor(D) + 1이다. 두 점 중 더 먼 것을 고르면 된다.
단, 거리가 1보다 가까운 경우 2는 성립할 수 없음에 유의한다.

주요 알고리즘 : 기하학, 애드 혹

출처 : JAG 2014S2 A번 // Petro 2015W2 A번
*/

double big(double a, double b) {
    return a > b ? a : b;
}

int main(void) {
    double d;
    scanf("%lf", &d);
    if (d < 0.8) printf("%.15f\n", d * sqrt(2));
    else printf("%.15f\n", big(d * sqrt(2), floor(d + 1)));
    return 0;
}