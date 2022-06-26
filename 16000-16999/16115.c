#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI acos(-1)

/*
���� : N(3 <= N <= 300000)���� ��(|X|, |Y| <= 10^6, �ڿ���)���� �̷���� �ܼ� �ٰ����� ��ǥ���� �ִ�.
�� �ٰ����� ������ �����ϰ�, � �� ���� �������� ���� �ʴ�.
�̶�, �� �ٰ����� �ݽð�������� ������ ���븦 �������� ����� ���� ������ �ϴ� �ּ� ������ ���Ѵ�.

�ذ� ��� : �켱 �������� ���� �ָ� ������ ���鸸�� ã�´�.
�� ����, �� ���� ������ atan2 �Լ��� �̿��� �����ش�. �� ������ ������ ���� ������ ������ ������
�ִ��� ���ϸ� �ȴ�. ��, ���۰� ���� ���̵� Ȯ���ؾ� �Ѵ�.

�ֿ� �˰��� : ������

��ó : ����� 2018D2 D��
*/

typedef struct point {
    long long x, y;
} point;

point pt[327680];
double ang[327680];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

long long getdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
    int n, acnt = 0;
    long long mdist = 0;
    double res = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pt[i].x, &pt[i].y);
        if (getdist(pt[i], (point) { 0, 0 }) > mdist) mdist = getdist(pt[i], (point) { 0, 0 });
    }
    for (int i = 0; i < n; i++) {
        if (pt[i].x == 0 && pt[i].y == 0) continue;
        if (getdist(pt[i], (point) { 0, 0 }) == mdist) {
            ang[acnt++] = atan2(pt[i].y, pt[i].x) / PI * 180.0;
        }
    }
    qsort(ang, acnt, sizeof(double), cmp1);
    for (int i = 1; i < acnt; i++) {
        if (ang[i] - ang[i - 1] > res) res = ang[i] - ang[i - 1];
    }
    if (ang[0] - ang[acnt - 1] + 360.0 > res) res = ang[0] - ang[acnt - 1] + 360.0;
    printf("%.9f", res);
    return 0;
}