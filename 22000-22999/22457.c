#include <stdio.h>
#include <math.h>
#define INF 103000.0
#define PI 3.14159265358979323846

/*
���� : N(N <= 100)���� ���� ��ǥ���� �־�����. �� ���� ��ǥ�� ũ��, ������ �־��� ��,
M��° ������ L��° ���� �̵��ϴµ� �ɸ��� ����� ���Ѵ�. ���� �������� �������� �̷���� �ְ�,
���� ���� ���е� ���̸� �����Ӱ� �̵� �����ϴ�. �ٸ� �� ���̴� ���� ����� �� ������ �Ÿ���ŭ
����� ���. ��ǥ�� ũ��� 1000 ������ �����̰�, ������ 72 ������ �ڿ����̴�.
������ �ݽð�������� ���ư���.

�ذ� ��� : �켱 �� ���� ������������ ��ǥ�� ���� ���صд�. �׷� ����, ��� ���� �ֿ� ����
���� ���� �Ÿ��� ���Ѵ�. �Ÿ��� �� ���� �� ���� �ָ����� �Ÿ� ��� �ּڰ����� ���ϰ�,
���� ������ �Ÿ��� �����ϴ� ��� 0, �� �ܿ��� ���� ���� ������ ��� �ֿ� ���� �ּڰ����� ���Ѵ�.
���� ���� ���� �Ÿ��� ������ ���� ������ ���� ���� ���� �ִ� ��� ���� ���� ���� �Ÿ� ������ ����,
�� �ܿ��� ���� ����� ���� ���� �Ÿ��� ���س��� �ȴ�.
��� �� �ֿ� ���� �Ÿ��� �������� �÷��̵�-���� �˰����� �̿��� �ִܰŸ��� ������ ����,
M��°���� L��°���� �Ÿ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ������, ���� ����, ���Ʈ ����, �÷��̵�-����

��ó : JAG 2012D D��
*/

typedef struct point {
    double x, y;
} point;

point star[128][5];
double dist[128][128];

double torad(double x) {
    return x * PI / 180.0;
}

point getstarpoint(double x, double y, double a, double r) {
    point res = { x, y };
    res.x += r * -sin(torad(a));
    res.y += r * cos(torad(a));
    return res;
}

double ccw(point p1, point p2, point p3) {
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

double crossproduct(point v1s, point v1e, point v2s, point v2e) {
    return (v1e.x - v1s.x) * (v2e.x - v2s.x) + (v1e.y - v1s.y)* (v2e.y - v2s.y);
}

int linecross(point p1s, point p1e, point p2s, point p2e) {
    if (ccw(p1s, p1e, p2s) * ccw(p1s, p1e, p2e) < 0 &&
        ccw(p2s, p2e, p1s) * ccw(p2s, p2e, p1e) < 0) return 1;
    else return 0;
}

double linepointdist(point ls, point le, point p) {
    if (crossproduct(ls, le, ls, p) < 0) {
        return sqrt((ls.x - p.x) * (ls.x - p.x) + (ls.y - p.y) * (ls.y - p.y));
    }
    else if (crossproduct(le, ls, le, p) < 0) {
        return sqrt((le.x - p.x) * (le.x - p.x) + (le.y - p.y) * (le.y - p.y));
    }
    else {
        double a = le.y - ls.y, b = ls.x - le.x;
        double c = -(ls.x * a + ls.y * b);
        return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
}

double getlinedist(point p1s, point p1e, point p2s, point p2e) {
    double res = INF;
    if (linecross(p1s, p1e, p2s, p2e)) return 0.0;
    if (linepointdist(p1s, p1e, p2s) < res) res = linepointdist(p1s, p1e, p2s);
    if (linepointdist(p1s, p1e, p2e) < res) res = linepointdist(p1s, p1e, p2e);
    if (linepointdist(p2s, p2e, p1s) < res) res = linepointdist(p2s, p2e, p1s);
    if (linepointdist(p2s, p2e, p1e) < res) res = linepointdist(p2s, p2e, p1e);
    return res;
}

double getstardist(int a, int b) {
    double res = INF, tmp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp = getlinedist(star[a][i], star[a][(i + 1) % 5], star[b][j], star[b][(j + 1) % 5]);
            if (tmp < res) res = tmp;
        }
    }
    return res;
}

int main(void) {
    int n, m, l;
    double x, y, a, r;
    while (1) {
        scanf("%d %d %d", &n, &m, &l);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &x, &y, &a, &r);
            for (int j = 0; j < 5; j++) {
                star[i][j] = getstarpoint(x, y, a + 144.0 * j, r);
            }
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0.0;
            for (int j = i + 1; j < n; j++) {
                dist[i][j] = getstardist(i, j);
                dist[j][i] = dist[i][j];
            }
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printf("%.9lf\n", dist[m - 1][l - 1]);
    }
    return 0;
}