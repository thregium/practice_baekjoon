#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795

/*
문제 : N(N <= 100)개의 과녁이 좌표평면상에 선분 형태로 주어진다. 원점에서 임의의 방향으로
화살을 쏘았을 때 맞출 수 있는 과녁의 개수를 구한다. 화살은 모든 과녁을 통과하며,
모든 과녁은 원점을 지나지 않는다.

해결 방법 : atan2()함수를 통해 각 과녁의 시작점과 끝점 좌표를 구한다. 그 후, 각 과녁이 원점에 대해
이루는 각을 구해서 전체에서의 비율로 나눈 값을 모든 과녁에 대해 더하면 답이 된다.
원점에 대해 이루는 각은 180도를 넘지 않음을 이용한다.

주요 알고리즘 : 수학, 기하학, 확률론

출처 : Arab 2012 G번
*/

double small(double a, double b) {
    return a < b ? a : b;
}

int main(void) {
    int t, n, x1, y1, x2, y2;
    double r, a1 = 0.0, a2 = 0.0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            a1 = atan2(y1, x1);
            a2 = atan2(y2, x2);

            r += small(fabs(a1 - a2), PI * 2.0 - fabs(a1 - a2)) / (PI * 2.0);
        }
        printf("%.5f\n", r + 0.000000000001);
    }
    return 0;
}