#include <stdio.h>
#include <math.h>

/*
���� : N(N <= 100)���� 120�� ���� �̵����� �̷���� �ܼ� �ٰ����� �־��� ��,
�� �ٰ����� ���ԵǴ� ���� �ﰢ���� ������ ���Ѵ�. �� �ٰ����� �ѷ��� 1000 ���ϴ�.

�ذ� ��� : �־��� �ٰ����� ���������� ã�� ����, �� ��ġ�� �̿��� �� ������ ���̸� ���Ѵ�.
�� ���̸� ���� �ﰢ���� ũ��� ���� ���� �ݿø��ϸ� ���� �ȴ�.

�ֿ� �˰��� : ������, �ٰ����� ����, �ùķ��̼�

��ó : BAPC 2015P C��
*/

typedef struct fpoint {
    double x, y;
} fpoint;

fpoint pt[128];

double getfarea(fpoint* poly, int n) {
    //N�� �ٰ����� ���̸� ������
    double area = 0;
    for (int i = 0; i < n - 1; i++) {
        area += poly[i].x * poly[i + 1].y;
        area -= poly[i + 1].x * poly[i].y;
    }
    area += poly[n - 1].x * poly[0].y;
    area -= poly[0].x * poly[n - 1].y;

    if (area < 0) area *= -1;
    return area / 2.0;
}

int main(void) {
    int t, n, l;
    double x, y, res;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        x = 0.0, y = 0.0;
        pt[0].x = x, pt[0].y = y;
        for (int i = 1; i <= n; i++) {
            scanf(" %c %d", &c, &l);
            if (c == 'x') x += l;
            else if (c == 'y') {
                x += l / 2.0;
                y += l / 2.0 * sqrt(3);
            }
            else if (c == 'z') {
                x -= l / 2.0;
                y += l / 2.0 * sqrt(3);
            }
            else return 1;
            pt[i].x = x, pt[i].y = y;
        }

        res = getfarea(pt, n + 1);
        printf("%.0f\n", round(res / sqrt(3) * 4.0));
    }
    return 0;
}