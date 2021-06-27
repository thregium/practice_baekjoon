#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : 3���� ��ǥ N(N <= 100000)���� �־��� ��, �߽��� ������ ���� �� K�� �̻��� �����ϱ� ���ؼ���
�������� �ּ��� �󸶰� �Ǿ�� �ϴ��� ���Ѵ�.

�ذ� ��� : �������� �� ��ǥ������ �Ÿ��� ��Ÿ����� ������ �̿��� ���� ��, ��� ���� �Ÿ��� �����Ͽ� K��° �Ÿ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, 3����, ��Ÿ��� ����, ����

��ó : UKIEPC 2019 D��
*/

double dist[103000];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    double x, y, z;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &x, &y, &z);
        dist[i] = sqrt(x * x + y * y + z * z);
    }
    qsort(dist, n, sizeof(double), cmp1);
    printf("%.9f", dist[k - 1]);
    return 0;
}