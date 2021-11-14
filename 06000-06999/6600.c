#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
문제 : 일직선상에 있지 않은 3개의 점이 주어질 때, 해당 세 점에 외접하는 원의 둘레를 구한다.

해결 방법 : 외심을 구한 후 한 점과의 거리를 통해 반지름을 구하고 이를 이용해 둘레를 구한다.

주요 알고리즘 : 기하학

출처 : Ulm 1996 C번 // SLPC 2000 1번
*/

int main(void) {
    double n, x1, y1, x2, y2, x3, y3, l1, l2, l3;
    double d1, d2, c1, c2, rx, ry, res;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        if (y1 == y2) {
            d1 = -(double)(x3 - x2) / (double)(y3 - y2);
            c1 = (y3 + y2) / 2.0 - (x3 + x2) / 2.0 * d1;
            d2 = -(double)(x1 - x3) / (double)(y1 - y3);
            c2 = (y1 + y3) / 2.0 - (x1 + x3) / 2.0 * d2;
        }
        else if (y2 == y3) {
            d1 = -(double)(x2 - x1) / (double)(y2 - y1);
            c1 = (y2 + y1) / 2.0 - (x2 + x1) / 2.0 * d1;
            d2 = -(double)(x1 - x3) / (double)(y1 - y3);
            c2 = (y1 + y3) / 2.0 - (x1 + x3) / 2.0 * d2;
        }
        else {
            d1 = -(double)(x2 - x1) / (double)(y2 - y1);
            c1 = (y2 + y1) / 2.0 - (x2 + x1) / 2.0 * d1;
            d2 = -(double)(x3 - x2) / (double)(y3 - y2);
            c2 = (y3 + y2) / 2.0 - (x3 + x2) / 2.0 * d2;
        }
        rx = (c2 - c1) / (d1 - d2);
        ry = rx * d1 + c1;
        res = sqrt(pow(rx - x1, 2) + pow(ry - y1, 2)) * PI * 2;

        printf("%.2f\n", res);
    }
    return 0;
}