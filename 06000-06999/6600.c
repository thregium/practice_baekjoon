#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
���� : �������� ���� ���� 3���� ���� �־��� ��, �ش� �� ���� �����ϴ� ���� �ѷ��� ���Ѵ�.

�ذ� ��� : �ܽ��� ���� �� �� ������ �Ÿ��� ���� �������� ���ϰ� �̸� �̿��� �ѷ��� ���Ѵ�.

�ֿ� �˰��� : ������

��ó : Ulm 1996 C�� // SLPC 2000 1��
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