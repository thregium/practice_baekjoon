#include <stdio.h>

/*
���� : A�� B�� ��ȯ�� �־��� ��, N(N <= 100000)���� ������ ���Ѵ�. �Ǽ��� A �Ǵ� B�� �־��� ��,
A�� �־����� �ش緮�� A�� ���� B�� ��, B�� �־����� �ش����� B�� ���� A�� ���� ����Ѵ�.

�ذ� ��� : A�� ���� B�� ���� Z * B / A�� ���� �� �ְ�(Z�� �־��� �Ǽ�), B�� ���� A�� ���� Z * A / B�� ���� �� �ִ�.

�ֿ� �˰��� : ����

��ó : CornH 2016 J��
*/

int main(void) {
    double x, y, z;
    int n;
    char q;
    scanf("%lf %lf", &x, &y);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %c", &z, &q);
        if (q == 'A') printf("%.9f\n", z * y / x);
        else if (q == 'B') printf("%.9f\n", z * x / y);
        else return 1;
    }
    return 0;
}