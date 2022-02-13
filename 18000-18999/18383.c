#include <stdio.h>
#include <math.h>
#define INF 10123456789876543210123456789.0
#define PI 3.14159265358979323846

/*
���� : N(N <= 30)���� ���� �־�����. �� ���� ��ǥ�� ������ 500 ������ �����̴�.
�̶�, ��� ������ �����ϴ� ���� ���� ���簢���� ���̸� ���Ѵ�.

�ذ� ��� : ������ �������� ���� ���簢���� ���̰� �۾����� ������ ã�Ƴ�����.
�� �������� ���簢���� ���̴� �ش� ���������� X��ǥ, Y��ǥ�� ���� ���� ����,
X�� Y��ǥ�� �ִ� - �ּڰ� �� ū ���� ������ ����.
�켱 ������ ���� ������ ���� ���̰� ���� �۾����� ������ ã�� ����,
������ �������� ���̸� ���� �ٿ������� �ȴ�.

�ֿ� �˰��� : ������, �̺� Ž��, �޸���ƽ?

��ó : Kabul 2018 B��
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