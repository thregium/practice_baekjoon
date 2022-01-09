#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
���� : N(N <= 100)���� ���� ���ʷ� �̾� ������� �Ʒ��� ������ ������ ���� ������ �־�����.
�̶�, X��ǥ A�� ���� �������̰� �� ���� ���̰� 1�� ���簢���� X��ǥ ��� �������� ����
B(0 <= A < B <= 200)���� �̵���ų ��, ���������� ���簢���� ������ ���� ���Ѵ�.
�־����� ��� ���� 0 �̻� 200 ������ ���� ���̸�, �Ǽ� ������ ���� ���� �޶����� ���� �־����� �ʴ´�.
���簢���� �̲������� �ʰ� ���⸸ �ϸ�, B���� �̵��� ���� ������ �� ���� B �̻��� �� ����̴�.

�ذ� ��� : ���簢���� ���� �������� �̵��ϱ� ������ �ش� ������ Ÿ�� 1���� �Ÿ��� �����̰� �ȴ�.
���� ������ Ÿ�� ���� 3������ �ִµ�, �ϳ��� ���� ���а��� �Ÿ��� 1 ���ϰ� �� ���,
�� �ϳ��� ���� ���а� �̷�� ���� �����̰�, �Ÿ��� sqrt(2) ���ϰ� �� ���, ���������� �ٴ��� ���а� �̷�� ����
�����̰�, �Ÿ��� sqrt(2) ���ϰ� �� ����̴�.
�� ��쿡 ���� �Ÿ��� ���� ������ �Ÿ��� �̿��� ���� �� �ְ�, ���� �������� �̵��ϴ� ��� ������ ����
��2 �ڻ��� ��Ģ�� �̿��Ͽ� �ö� ���̸� ���Ͽ� �� �� �ִ�. ����, �Ź� �̵� �Ÿ��� ����� ������ �� �� �ִ�.
�̸� �̿��Ͽ� ���� ���� B���� �̵��� ������ ȸ�� Ƚ���� ���ϰ� 4�� ���� �������� ���ϸ� ���� �� �� �ִ�.
�� �������� �߻��� �� �ִ� ���� ��Ȳ�鿡 ���� ó���� �� �ؾ� �Ѵ�.

�ֿ� �˰��� : ������, ���̽� ��ũ

��ó : JAG 2011S4 G��
*/

double point[256][2];
char* color[] = { "Red", "Green", "Blue", "White" };

double getangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    //�� ������ �̷�� ���� ���Ѵ�.
    double cross = (x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3);
    double l1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double l2 = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
    return PI - acos(cross / l1 / l2);
}

double pointlinedist(double px, double py, double x1, double y1, double x2, double y2) {
    //���� ���а��� �Ÿ��� ���Ѵ�.
    if (x1 == x2) return fabs(px - x1);
    double dxy = fabs((y2 - y1) / (x2 - x1)) + fabs((x2 - x1) / (y2 - y1));
    double yp = y1 + (y2 - y1) * ((px - x1) / (x2 - x1));
    double cx = px + fabs(py - yp) / dxy;
    double cy = y1 + (y2 - y1) * ((cx - x1) / (x2 - x1));
    //printf("%lf\n", sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy)));
    if (cx < x1) return sqrt((x1 - px) * (x1 - px) + (y1 - py) * (y1 - py));
    else return sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));
}

double getcrossx(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    //�� ������ ������ ������ X��ǥ�� ���Ѵ�.
    double d1 = (y2 - y1) / (x2 - x1);
    double d2 = (y4 - y3) / (x4 - x3);
    double in1 = y1 - x1 * d1;
    double in2 = y3 - x3 * d2;
    return (in1 - in2) / (d2 - d1);
}

int main(void) {
    int n, itv = 0, cnt = 0; //itv: ���� ���� ����, cnt: ȸ�� Ƚ��
    double a, b, y, slop, an, an2, xdiff, cx, t; //a: ���� ���簢���� ���� x��ǥ, b: ��ǥ x��ǥ, \
    y: ���� ���簢���� ���� y��ǥ, slop: ���� ������ ���, xdiff: ������ ���� 1 �̵��� x��ǥ ��ȭ��\
    an: ���� ���а� ���� ������ ��(����), an2: ���� ���а� �ٴ��� ������ ��(����), \
    cx: ���� ���а� �ٴ��� ������ �������� �� �� ������ X��ǥ, t: ���� �������� �ö󰡴� ����
    scanf("%d %lf %lf", &n, &a, &b);
    if (n < 2) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &point[i][0], &point[i][1]);
    }
    //���� ������ ���Ƿ� �߰��Ѵ�.
    point[n][0] = point[n - 1][0] * 2 - point[n - 2][0];
    point[n][1] = point[n - 1][1] * 2 - point[n - 2][1];
    slop = (point[1][1] - point[0][1]) / (point[1][0] - point[0][0]);
    xdiff = 1.0 / sqrt(slop * slop + 1);
    while (a < b) {
        y = point[itv][1] + (point[itv + 1][1] - point[itv][1]) *
            ((a - point[itv][0]) / (point[itv + 1][0] - point[itv][0]));
        //printf("%lf %lf\n", a, y); //���� ��ǥ ���(����׿�)
        an = getangle(point[itv][0], point[itv][1], point[itv + 1][0], point[itv + 1][1],
            point[itv + 1][0], point[itv + 1][1], point[itv + 2][0], point[itv + 2][1]);
        an2 = getangle(point[itv][0], point[itv][1], point[itv + 1][0], point[itv + 1][1],
            point[itv + 2][0], point[itv + 2][1], point[itv + 3][0], point[itv + 3][1]);
        if (pointlinedist(a, y, point[itv + 1][0], point[itv + 1][1], point[itv + 2][0], point[itv + 2][1]) < 1
            && itv < n - 2) {
            //���� �������� �Ѿ�� ���(90�� ȸ��)
            t = (point[itv + 1][0] - a) * (1.0 / xdiff);
            t = cos(an) * t + sqrt((t * t) * (cos(an) * cos(an) - 1) + 1);
            itv++;
            slop = (point[itv + 1][1] - point[itv][1]) / (point[itv + 1][0] - point[itv][0]);
            xdiff = 1.0 / sqrt(slop * slop + 1);
            a = point[itv][0] + t * xdiff;
        }
        else if (pointlinedist(a, y, point[itv + 1][0], point[itv + 1][1],
            point[itv + 2][0], point[itv + 2][1]) < sqrt(2) && an < PI / 2) {
            //���� �������� �Ѿ�� ���(180�� ȸ��)
            t = (point[itv + 1][0] - a) * (1.0 / xdiff);
            t = cos(an) * t + sqrt((t * t) * (cos(an) * cos(an) - 1) + 2);
            itv++;
            cnt++;
            slop = (point[itv + 1][1] - point[itv][1]) / (point[itv + 1][0] - point[itv][0]);
            xdiff = 1.0 / sqrt(slop * slop + 1);
            a = point[itv][0] + t * xdiff;
        }
        else if (pointlinedist(a, y, point[itv + 2][0], point[itv + 2][1],
            point[itv + 3][0], point[itv + 3][1]) < sqrt(2) && an2 < PI / 2 && itv < n - 3) {
            //�ٴ��� �������� �Ѿ�� ���(180�� ȸ��)
            cx = getcrossx(point[itv][0], point[itv][1], point[itv + 1][0], point[itv + 1][1],
                point[itv + 2][0], point[itv + 2][1], point[itv + 3][0], point[itv + 3][1]);
            t = (cx - a) * (1.0 / xdiff);
            t = cos(an2) * t + sqrt((t * t) * (cos(an2) * cos(an2) - 1) + 2);
            itv += 2;
            cnt++;
            slop = (point[itv + 1][1] - point[itv][1]) / (point[itv + 1][0] - point[itv][0]);
            xdiff = 1.0 / sqrt(slop * slop + 1);
            a = cx + t * xdiff;
        }
        else a += xdiff;
        if (a > b) break;
        cnt++;
    }
    //printf("%d\n", cnt);
    printf("%s", color[cnt & 3]);
    return 0;
}