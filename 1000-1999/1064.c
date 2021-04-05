#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : �� ���� ��ǥ�� �־��� �� �� ���� �߰��ؼ� ���� �� �ִ� ����纯�� �� ���� �ѷ��� �� �Ͱ� ���� �ѷ��� ª�� ���� �ѷ� ���� ���Ѵ�.
��, �־��� ��ǥ�δ� ����纯���� ���� �� ���� ��� -1�� ����Ѵ�.

�ذ� ��� : �� ���� �߰��ؼ� ����纯���� ���� �� ���� ���� �� ���� ������ ���̴� ����̴�.
CCW�� �̿��ϰų� ���� �� ������ ������ �� ���а� ���̰� ������ �̿��ؼ� �� �� �ִ�.
����纯���� �ѷ��� �� ���������� �̾��� �� ���� ������ �� * 2�̹Ƿ� ���� �� �Ͱ� ���� ª�� ���� (�� �� + �߰� �� - (�߰� �� + ª�� ��)) * 2
= (�� �� - ª�� ��) * 2�� �ȴ�. �� ������ ���̴� ��Ÿ����� ������ �̿��� ����Ѵ�.

�ֿ� �˰��� : ������, ��Ÿ����� ����
*/

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int xa, ya, xb, yb, xc, yc;
    double l[3];
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    if (xa * yb + xb * yc + xc * ya - (xb * ya + xc * yb + xa * yc) == 0) printf("-1"); //������ �ִ� ���
    else {
        l[0] = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
        l[1] = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
        l[2] = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
        qsort(l, 3, sizeof(double), cmp1);
        printf("%.15lf", (l[2] - l[0]) * 2);
    }
    return 0;
}