#include <stdio.h>
#include <math.h>

/*
���� : [L, R](0 <= L < R <= 12) �������� �̺� Ž���� K(K <= 30)ȸ ������ �� ���� ����
T�� ���� E(T, E <= 12) �̳��� Ȯ���� ���Ѵ�. ��, �� �ܰ踶�� �߸� ������ Ȯ���� P(0 <= P <= 1)�̴�.

�ذ� ��� : ������ �������� �̺� Ž���� Kȸ �����Ѵ�. ��, ��ü ������
T�� ���� E���� ū ��� ���̻� �̺� Ž���� �����ϴ��� ���ϴ� ������ ���� �����Ƿ� 0�� ��ȯ�ϰ�,
��ü ������ �ش� ���� �̳��� ��� �ݵ�� ���ϴ� ������ ���Ƿ� �ش� ������ �� Ȯ���� ��ȯ�Ѵ�.
�� �� �ƴ϶�� �������� ������ �� Ȯ���� Ȯ���ϸ� ������ ���� ���ؼ� ��ȯ�Ѵ�.
Kȸ �̺� Ž���� ������ ��쿡�� �߾Ӱ��� Ȯ���ϰ� �� ���� ���� ���̶�� Ȯ����, �ƴ϶�� 0�� ��ȯ�Ѵ�.

�ֿ� �˰��� : ����, Ȯ����, ���� ����

��ó : JAG 2011S3 B��
*/

double slep(int k, double l, double r, double p, double e, double t, double pp) {
    if (l > t + e || r < t - e) return 0;
    else if (t - e <= l && r <= t + e) return pp;
    if (k == 0) {
        if (fabs((l + r) / 2.0 - t) <= e) return pp;
        else return 0;
    }
    else {
        if ((l + r) / 2.0 >= t) {
            return slep(k - 1, l, (l + r) / 2.0, p, e, t, pp * (1.0 - p)) +
                slep(k - 1, (l + r) / 2.0, r, p, e, t, pp * p);
        }
        else {
            return slep(k - 1, l, (l + r) / 2.0, p, e, t, pp * p) +
                slep(k - 1, (l + r) / 2.0, r, p, e, t, pp * (1.0 - p));
        }
    }
}

int main(void) {
    int k;
    double l, r, p, e, t;
    scanf("%d %lf %lf%lf%lf%lf", &k, &l, &r, &p, &e, &t);
    printf("%.9f\n", slep(k, l, r, p, e, t, 1));
    return 0;
}