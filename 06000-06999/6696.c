#include <stdio.h>

/*
���� : (0, 0)���� �����Ͽ� �ݿ�������� ���� �ð��� 50m^2�� ä���� ������.
�̶�, �־����� �Ǽ� ��ǥ (X, Y)(|X| <= 1000, 0 <= Y <= 1000)�� ���� ä������ �ð��� ���Ѵ�.

�ذ� ��� : ��Ÿ����� ������ �����ϸ� X * X + Y * Y * pi / 2 / 50�� �ø��� ������ ��� �����ϴ�.

�ֿ� �˰��� : ������, ��Ÿ��� ����

��ó : CTUO 2002 W��
*/

int main(void) {
    double x, y;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2002\\water.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2002\\water_t.out", "w", stdout);
    while (1) {
        scanf("%lf %lf", &x, &y);
        if (x == 0 && y == 0) break;
        printf("The property will be flooded in hour %d.\n", (int)((x * x + y * y) * 1.5707963 / 50) + 1);
    }
    return 0;
}