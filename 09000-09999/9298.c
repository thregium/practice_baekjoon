#include <stdio.h>

/*
���� : N(N <= 100)���� ���� �����ϴ� ���� ���� ��ǥ��鿡 ������ ������ ���簢���� ���̿� �ѷ��� ���Ѵ�.

�ذ� ��� : �� ���� �� ���� x��ǥ�� ���� ������ x��ǥ�� ū �������� �Ÿ��� ������ ���̰� �ǰ�
y��ǥ�� ���� ���� ������ ū �������� �Ÿ��� ������ ���̰� �ȴ�. �� ������ �̿��� ���̿� �ѷ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : UVa 2012 C��
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