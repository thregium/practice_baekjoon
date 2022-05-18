#include <stdio.h>

/*
���� : N(2 <= N <= 50)���� �㰡 ���������� �����δ�. �̶�, ��ǥ�࿡ ������ ���簢�� ������ ��Ÿ����
��� �㸦 ���� �� �ִ� ���� ���� �� ���� ���� L�� ���Ѵ�.
���� ��ǥ�� �̵� �ӵ��� ���� 1000 ������ ������.

�ذ� ��� : �ð� T�� ���� ��Ÿ�� ������ ũ��� �Ʒ��� ������ ������ �׸��� ������ ��� Ž���� �����ϴ�.
����, ��� Ž���� ���� ������ �ּҰ� �Ǵ� ������ ã���� �ȴ�. �ִ��� 2000���� �θ� �ȴ�.

�ֿ� �˰��� : ������, ��� Ž��

��ó : SRM 426 D1 2��
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