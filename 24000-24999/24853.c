#include <stdio.h>

/*
���� : �־��� ������ �׷����� ���� �� �� ���� ȿ���� ������ ��� ���� ���� ���� �� �� �ִ�
���� �ð������� �� �� �ִ� ���� ���� ���Ѵ�.

�ذ� ��� : �׷����� ������ ���� ������ ���°� �Ǳ� ������ ��� Ž���� ���� ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ��� Ž��

��ó : ROI 2021H K��
*/

int main(void) {
    double p, t, lo, hi, mid1, mid2, eff1, eff2;
    scanf("%lf %lf", &p, &t);
    lo = 0, hi = t / 3.0;
    for (int i = 0; i < 401; i++) {
        mid1 = (lo * 2 + hi) / 3;
        mid2 = (lo + hi * 2) / 3;
        if (mid1 < t / 6.0) eff1 = p * (mid1 / (t / 6.0)) / 100.0;
        else eff1 = (p + (mid1 - t / 6.0) / (t / 6.0) * (100.0 - p)) / 100.0;
        if (mid2 < t / 6.0) eff2 = p * (mid2 / (t / 6.0)) / 100.0;
        else eff2 = (p + (mid2 - t / 6.0) / (t / 6.0) * (100.0 - p)) / 100.0;

        if ((t - mid1) * eff1 < (t - mid2) * eff2) lo = mid1;
        else hi = mid2;
    }
    printf("%.9f", (t - mid1) * eff1 * 100.0);
    return 0;
}