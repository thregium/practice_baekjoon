#include <stdio.h>

/*
���� : ������ �ٰ����� �־��� �� �� �ٰ����� ������ ���Ѵ�.

�ذ� ��� : �Ź߲� ������ �̿��Ѵ�.

�ֿ� �˰��� : ����, ������
*/

double x[10240], y[10240];

int main(void) {
    int n;
    double area = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        area += x[i] * y[i + 1];
        area -= x[i + 1] * y[i];
    }
    area += x[n - 1] * y[0];
    area -= x[0] * y[n - 1];
    if (area < 0) area *= -1;
    area /= 2;
    printf("%.1f", area);
    return 0;
}