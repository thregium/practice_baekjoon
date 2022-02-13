#include <stdio.h>
#include <math.h>
#define INF 10123456789876543210123456789.0
#define PI 3.14159265358979323846

/*
문제 : N(N <= 30)개의 점이 주어진다. 각 점의 좌표는 절댓값이 500 이하인 정수이다.
이때, 모든 점들을 포함하는 가장 작은 정사각형의 넓이를 구한다.

해결 방법 : 각도를 돌려가며 가장 정사각형의 넓이가 작아지는 지점을 찾아나간다.
각 각도에서 정사각형의 넓이는 해당 각도에서의 X좌표, Y좌표를 새로 구한 다음,
X와 Y좌표의 최댓값 - 최솟값 중 큰 값의 제곱과 같다.
우선 적당히 많은 각도에 대해 넓이가 가장 작아지는 각도를 찾은 다음,
범위를 좁혀가며 넓이를 점점 줄여나가면 된다.

주요 알고리즘 : 기하학, 이분 탐색, 휴리스틱?

출처 : Kabul 2018 B번
*/

int dot[32][2];

double big(double a, double b) {
    return a > b ? a : b;
}

double getres(int n, double angle) {
    double xl = INF, yl = INF, xh = -INF, yh = -INF, px, py;
    for (int j = 0; j < n; j++) {
        px = dot[j][1] * sin(angle) + dot[j][0] * cos(angle);
        py = dot[j][1] * cos(angle) - dot[j][0] * sin(angle);
        if (px < xl) xl = px;
        if (px > xh) xh = px;
        if (py < yl) yl = py;
        if (py > yh) yh = py;
    }
    return big(xh - xl, yh - yl) * big(xh - xl, yh - yl);
}

int main(void) {
    int t, n, ri;
    double r, ra, angle, unit;
    //freopen("E:\\PS\\ICPC\\Asia West Continent\\Kabul\\2018\\Q+S+T\\Q+S+T\\testCases\\TATCK\\in-2.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = INF;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &dot[i][0], &dot[i][1]);
        }
        for (int i = 0; i < 10300; i++) {
            angle = i * PI / 10300.0;
            if (getres(n, angle) < r) {
                r = getres(n, angle);
                ra = angle;
            }
        }
        unit = PI / 10300.0;
        for (int i = 0; i < 39; i++) {
            unit /= 1024;
            ri = 512;
            for (int j = 0; j < 1024; j++) {
                angle = ra + (j - 512) * unit;
                if (getres(n, angle) < r) {
                    r = getres(n, angle);
                    ri = j;
                }
            }
            ra = ra + (ri - 512) * unit;
        }
        printf("%.2f\n", r);
    }
    return 0;
}