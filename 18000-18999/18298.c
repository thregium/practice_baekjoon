#include <stdio.h>

/*
���� : N(N <= 1000)���� P_i(P_i <= 50)�� �ٰ����� ���� ���� ���Ѵ�. �� �ٰ����� �ܼ� �ٰ����̸�,
���� ��ġ�� �ʴ´�.

�ذ� ��� : �� �ٰ����� ���̸� ���ϰ� ���� ���� ���� 2�� ������ �ȴ�.

�ֿ� �˰��� : ������, �ٰ����� ����

��ó : SWERC 2019 F��
*/

typedef struct point {
    long long x, y;
} point;

point poly[64];

long long getarea(point* poly, int n) {
    //N�� �ٰ����� ����(*2)�� ������
    long long area = 0;
    for (int i = 0; i < n - 1; i++) {
        area += poly[i].x * poly[i + 1].y;
        area -= poly[i + 1].x * poly[i].y;
    }
    area += poly[n - 1].x * poly[0].y;
    area -= poly[0].x * poly[n - 1].y;

    if (area < 0) area *= -1;
    return area;
}

int main(void) {
    int n, p;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        for (int j = 0; j < p; j++) {
            scanf("%lld %lld", &poly[j].x, &poly[j].y);
        }
        r += getarea(poly, p);
    }
    printf("%lld", r >> 1);
    return 0;
}