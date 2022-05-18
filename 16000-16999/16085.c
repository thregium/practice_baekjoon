#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795

/*
���� : Y = 0�� ���� ���ΰ� �ִ�. ���θ� ���� ���� Ÿ�� �����ð��� C, �ɾ�� �ƹ� �������ε�
�����ð��� W�� �ӷ����� �̵� ������ ��, (0, 0)���� ����� �� �ð� T(C, W, T <= 100, �ڿ���) ��
������ �� �ִ� ������ ���̸� ���Ѵ�.

�ذ� ��� : W�� C �̻��� ��쿡 �̵� ������ ������ �������� WT�� ���� �ȴ�.
C�� W���� Ŀ���� �̵� ������ ������ �����ٰ� (0, WC), (0, -WC)���� �������� WT�̰� �߽��� (0, 0)�� ����
���� ������ ���θ� �߰��� �����ϰ� �ȴ�. �� �κ��� ������ ����Ͽ� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : MNPC 2018 I��
*/

int main(void) {
    int t;
    double tm, w, c, wl, cl, sl, area;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %lf %lf", &tm, &w, &c);
        wl = w * tm, cl = c * tm;

        if (wl + 1E-9 >= cl) printf("%.3f\n", wl * wl * PI);
        else {
            sl = sqrt(cl * cl - wl * wl);
            area = wl * wl * PI;
            area += sl * wl * 2;
            area -= acos(wl / cl) * wl * wl * 2;
            printf("%.3f\n", area);
        }
    }
    return 0;
}