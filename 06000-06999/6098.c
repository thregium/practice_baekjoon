#include <stdio.h>

/*
���� : �ذ� += 10^6�� ������ �����ϰ� �ִ� N(N <= 11)�� �������� �־��� ��,
�� �������� �� * 1000�� �ڿ��� ������ ������ ���� ���Ѵ�. ��, �߱��� ���� ���� �־����� �ʴ´�.
����, ��� ���� ���е� 1E-6���� ����� ���� �� �ִ�.

�ذ� ��� : +100���� -100������ ������ ������ �������� �ذ� �ִ� ���� ã�Ƴ�����. �ذ� �����ϰ� ������ ��ȣ�� �ٸ��� ������
��� ���� ��ȣ�� ���� ���� ������ ���� �� �ִ�. ��� ���� ����� ��� �����ϴ� �׷������ ���������� ������,
�����ϴ� �׷������ �������� ������ �ǰ�, ������ ��쿡�� �� �ݴ�� ������ �ȴ�.

�ֿ� �˰��� : ����, �Ķ��Ʈ��, ��ġ�ؼ�

��ó : USACO 2009F B2��
*/

double coef[16];

double calc_poly(int n, double x) {
    double r = 0, t = 1;
    for (int i = 0; i <= n; i++) {
        r += coef[i] * t;
        t *= x;
    }
    return r;
}

int main(void) {
    int n, dir = 0;
    double lo = -1048576, hi = 1048576, mid;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &coef[i]);
    }
    if (calc_poly(n, lo) * calc_poly(n, hi) >= 0) return 1;
    if (calc_poly(n, lo) < 0) dir = 1;
    else dir = -1;

    while (hi - lo > 1E-7) {
        mid = (hi + lo) / 2;
        if (calc_poly(n, mid) > 0) {
            if (dir > 0) hi = mid;
            else lo = mid;
        }
        else {
            if (dir > 0) lo = mid;
            else hi = mid;
        }
    }
    printf("%lld", (long long)(hi * 1000LL));
    return 0;
}