#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
���� : �� ���� ��ǥ�� �� ������ ��ǥ ������ ������ �־��� ��, ��ǥ ������ ��ǥ�� ���Ѵ�.
��, �� ���� ������ ���ų� �ݴ밡 �Ǵ� ���� ����.

�ذ� ��� : �� ���� �ٶ󺸴� �������� ������ ���� ���� �� ������ ������ ã�´�. Y��� ������ ���� ���� ó���Ѵ�.

�ֿ� �˰��� : ������

��ó : NWERC 2002 C��
*/

int main(void) {
    int t, x1, y1, d1, x2, y2, d2;
    double ax1, an1, ax2, an2, rx; //x�װ� �����
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &x1, &y1, &d1);
        scanf("%d %d %d", &x2, &y2, &d2);
        if (d1 == 0 || d1 == 180) {
            ax2 = tan((90 - d2) * PI / 180);
            an2 = y2 - ax2 * x2;
            printf("%.4f %.4f\n", (double)x1, ax2 * x1 + an2);
        }
        else if (d2 == 0 || d2 == 180) {
            ax1 = tan((90 - d1) * PI / 180);
            an1 = y1 - ax1 * x1;
            printf("%.4f %.4f\n", (double)x2, ax1 * x2 + an1);
        }
        else {
            ax1 = tan((90 - d1) * PI / 180);
            an1 = y1 - ax1 * x1;
            ax2 = tan((90 - d2) * PI / 180);
            an2 = y2 - ax2 * x2;
            rx = (an2 - an1) / (ax1 - ax2);
            printf("%.4f %.4f\n", rx, rx * ax1 + an1);
        }
    }
    return 0;
}