#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
문제 : 두 점의 좌표와 두 점에서 목표 지점의 방향이 주어질 때, 목표 지점의 좌표를 구한다.
단, 두 점의 방향이 같거나 반대가 되는 일은 없다.

해결 방법 : 두 점이 바라보는 방향으로 직선을 그은 다음 두 직선의 교점을 찾는다. Y축과 평행한 경우는 따로 처리한다.

주요 알고리즘 : 기하학

출처 : NWERC 2002 C번
*/

int main(void) {
    int t, x1, y1, d1, x2, y2, d2;
    double ax1, an1, ax2, an2, rx; //x항과 상수항
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &x1, &y1, &d1);
        scanf("%d %d %d", &x2, &y2, &d2);
        if (d1 == 0 || d1 == 180) {
            ax2 = tan((90 - d2) * PI / 180);
            an2 = y2 - ax2 * x2;
            printf("%.4f %.4f\n", (double)x1, ax2 * x1 + an2);
        }
        else if (d2 == 0 || d2 == 180) {
            ax1 = tan((90 - d1) * PI / 180);
            an1 = y1 - ax1 * x1;
            printf("%.4f %.4f\n", (double)x2, ax1 * x2 + an1);
        }
        else {
            ax1 = tan((90 - d1) * PI / 180);
            an1 = y1 - ax1 * x1;
            ax2 = tan((90 - d2) * PI / 180);
            an2 = y2 - ax2 * x2;
            rx = (an2 - an1) / (ax1 - ax2);
            printf("%.4f %.4f\n", rx, rx * ax1 + an1);
        }
    }
    return 0;
}