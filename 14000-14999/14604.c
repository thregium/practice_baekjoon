#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� ���� ��ǥ���� �ִ�. �� ���� �������� ������� �����ϴ�.
�̶�, ������ �׾ ���ʿ��� ���� ���� ������ �� ��, �� ���� �� ���� �ִ� ������ ���Ѵ�.
� 3���� ���� ���� ������ ���� �ʴ�.

�ذ� ��� : ��� 2���� ���� �ֿ� ���� ���ʿ� �ش��ϴ� �� ���� �� ������ ���Ѵ�.
��� ���������� CCW�� �̿��ϸ� ������ ���� �� �ִ�.
���� ���ʿ� �� ���� ���ٸ� �� ������ ���� �� ����(+ �������� ���� �� ����)�� ���� ���� �ȴ�.

�ֿ� �˰��� : ������, ���Ʈ ����

��ó : ���ִ� 2017D1 G1��
*/

typedef struct point {
    long long x, y;
    int pn;
} point;

point pt[128];
char buff[32];

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1; //turn left(x->y^)
    else if (tri == 0) return 0;
    else return -1; //turn right
}

int main(void) {
    int n, pp, pn, mp, mn, np, nn, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %s", &pt[i].x, &pt[i].y, buff);
        if (!strcmp(buff, "LOVELYZ")) pt[i].pn = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pp = 0, pn = 0, mp = pt[i].pn + pt[j].pn, mn = 2 - (pt[i].pn + pt[j].pn), np = 0, nn = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (ccw(pt[i], pt[j], pt[k]) == 0) {
                    if (pt[k].pn) mp++;
                    else mn++;
                }
                else if (ccw(pt[i], pt[j], pt[k]) > 0) {
                    if (pt[k].pn) pp++;
                    else pn++;
                }
                else {
                    if (pt[k].pn) np++;
                    else nn++;
                }
            }

            if (pn == 0) {
                if (pp + mp > res) res = pp + mp;
            }
            if (nn == 0) {
                if (np + mp > res) res = np + mp;
            }
        }
    }
    printf("%d", res);
    return 0;
}