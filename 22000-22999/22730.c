#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : ���� N(N <= 100)���� ���� ����� �뼱�� �ִ�. �� �뼱�� �ڻ� �Ǵ� Ÿ�� �뼱�̸�,
���� �Ǵ� ���Ϸ� �̾�����. �̶�, �� �� A���� B�� �̵��ϴ� �뼱�� ������ ������ �ϴ�
����� ���ϸ� �մ� ����� ������ ���Ѵ�. ������ �뼱���� �ڻ� �뼱���� ���� ����,
Ÿ�� �뼱���� �ٸ� ���̿� �������� �Ѵ�.
�� �뼱�� ������, ������ ��ġ�� [-10000, 10000] ������ �����̴�. ����, �� �뼱�� ��ġ�� �ʰ�
�� ������ ���� �뼱�� �����ų� �ſ� �����(10^-9 �̳�) �������� ���� �뼱�� ������ �ʴ´�.

�ذ� ��� : �� �̹� ������ �뼱���� ���ο� �뼱�� �����ϴ� �� ���θ� Ȯ���Ѵ�.
�� �뼱�� �����ϴ� ��� �� �뼱�� ������ ���Ѵ�. ������ ���� ����, �뼱�� ���̸� Ȯ���ϰ�
�迭�� ����ִ´�. �� ���� �迭���� ������ ������� �����ϰ�, ������ ��ġ�� ���� �ٸ� ������
�������� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, ���� ����, ���̽� ��ũ, ����

��ó : JAG 2006D D��
*/

typedef struct station {
    double posx;
    double posy;
    int over;
} station;

station sta[128];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    station ai = *(station*)a;
    station bi = *(station*)b;
    if (fabs(bi.posx - ai.posx) < 5E-10) {
        return ai.posy > bi.posy ? 1 : ai.posy == bi.posy ? 0 : -1;
    }
    else return ai.posx > bi.posx ? 1 : ai.posx == bi.posx ? 0 : -1;
}

long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int dotinline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    if (ccw(x1, y1, x2, y2, x3, y3)) return 0;
    if (x3 > big(x1, x2) || x3 < small(x1, x2) || y3 > big(y1, y2) || y3 < small(y1, y2)) return 0;
    else return 1;
}

int crossline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4) {
    if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0 && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0) return 1;
    else if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2)) return 0;
    if (dotinline(x1, y1, x2, y2, x3, y3) || dotinline(x1, y1, x2, y2, x4, y4) || dotinline(x3, y3, x4, y4, x1, y1) || dotinline(x3, y3, x4, y4, x2, y2)) return 1;
    else return 0;
}

int main(void) {
    int t, xa, ya, xb, yb, n, m, xs, ys, xt, yt, o, l, r;
    double d1, d2, in1, in2;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\D4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\D4_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
        m = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d %d %d", &xs, &ys, &xt, &yt, &o, &l);
            if (crossline(xs, ys, xt, yt, xa, ya, xb, yb)) {
                sta[m].over = (!(o ^ l));
                while (xa == xb && xs == xt);
                if (xa == xb) {
                    d1 = (yt - ys) / (double)(xt - xs);
                    in1 = ya - xa * d1;
                    sta[m].posx = xa;
                }
                else if (xs == xt) {
                    d1 = (yb - ya) / (double)(xb - xa);
                    in1 = ya - xa * d1;
                    sta[m].posx = xs;
                }
                else {
                    d1 = (yb - ya) / (double)(xb - xa);
                    d2 = (yt - ys) / (double)(xt - xs);
                    in1 = ya - xa * d1;
                    in2 = ys - xs * d2;
                    sta[m].posx = (in1 - in2) / (d2 - d1);
                }
                sta[m].posy = sta[m].posx * d1 + in1;
                m++;
            }
        }
        qsort(sta, m, sizeof(station), cmp1);

        r = 0;
        for (int i = 1; i < m; i++) {
            if (sta[i].over != sta[i - 1].over) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}