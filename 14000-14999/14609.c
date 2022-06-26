#include <stdio.h>

/*
���� : K(K <= 10)�� ���׽��� �� ���� ���(<= 10, ���� �ƴ� ����)�� �־��� ��, [A, B](A < B <= 10)
������ ������ �Ͱ� N(N <= 10)���� �������� ������ ���б����� ���� ������ �ϴ� ���Ƿ� ���� ���Ѵ�.

�ذ� ��� : ���Ƿ��� ���� �ȿ��� �ݵ�� ���� �����ϸ� �� �������� �ᱣ���� ���� �����ϱ� ������
(��� ���� ��� �Ǵ� 0�̹Ƿ�) �Ű� ���� Ž���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��������, �Ķ��Ʈ��

��ó : ���ִ� 2017D2 D2��
*/

int coef[16];

double fx(int k, double x) {
    double res = 0.0, xx = 1.0;
    for (int i = 0; i <= k; i++) {
        res += xx * coef[i];
        xx *= x;
    }
    return res;
}

double func(int k, double ep, int a, int n, double dx) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += fx(k, a + dx * i + ep) * dx;
    }
    //printf("%.9f\n", res);
    return res;
}

int main(void) {
    int k, a, b, n;
    double actual = 0.0, tx, hi, lo, mid, dx;
    scanf("%d", &k);
    for (int i = k; i >= 0; i--) {
        scanf("%d", &coef[i]);
    }
    scanf("%d %d %d", &a, &b, &n);
    dx = (b - (double)a) / n;
    hi = dx, lo = 0.0;
    for (int i = 0; i <= k; i++) {
        tx = coef[i];
        for (int j = 0; j <= i; j++) tx *= b;
        tx /= (i + 1);
        actual += tx;
        tx = coef[i];
        for (int j = 0; j <= i; j++) tx *= a;
        tx /= (i + 1);
        actual -= tx;
    }

    for (int i = 0; i < 0401; i++) {
        mid = (lo + hi) / 2.0;
        if (func(k, mid, a, n, dx) < actual) lo = mid;
        else hi = mid;
    }
    printf("%.9f", lo);
    return 0;
}