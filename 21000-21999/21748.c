#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926253589793

/*
���� : ���� �ѷ��� N(N <= 180)���� �������� �ɰ��� �ִ�. �� �ɰ��� �������� ��ġ�� ������ �־��� ��,
��� ������ �����ϴ� ��Ÿ���� ���µ� ��� �ּ����� ��Ÿ�� ���̸� ���Ѵ�. ��, �ɰ��� �������� ��ġ�� �ʴ´�.

�ذ� ��� : �� �������� �״�� ���������� �ΰ� ������ ���̴� ȣ ���·� �մ� ���� ��Ÿ�� ���̸� �ּҷ� �� �� �ִ�.
�׷��� ���ؼ��� ó������ ���ֿ��� ������ ��Ÿ������ ���������� ������ �� ���̻��� �� ������ ������ ȣ�� �ٲپ� �θ� �ȴ�.
�׸��� �����̹Ƿ� �� �հ� �� �ڵ� �̾�� �Ѵٴ� ��ǵ� �ؾ�� �� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : ROI 2004H B��
*/

int frags[192][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getarc(int r, int deg) {
    if (deg > 180) deg = 360 - deg;
    return r * 2.0 * sin(deg * PI / 360.0);
}

int main(void) {
    int n, r;
    double fence = 0;
    scanf("%d %d", &n, &r);
    fence = r * PI * 2.0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &frags[i][0], &frags[i][1]);
    }
    qsort(frags, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n; i++) {
        fence -= r * PI * 2.0 * ((frags[i][0] - frags[i - 1][1] + 360) % 360) / 360.0;
        fence += getarc(r, (frags[i][0] - frags[i - 1][1] + 360) % 360);
    }
    fence -= r * PI * 2.0 * ((frags[0][0] - frags[n - 1][1] + 360) % 360) / 360.0;
    fence += getarc(r, (frags[0][0] - frags[n - 1][1] + 360) % 360);
    printf("%f", fence);
    return 0;
}