#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : N(N <= 100000)���� ���� �־�����. �� ���� ��ǥ�� ���� 10000 ������ �����̴�.
�̶�, ���� �� �� ���� �Ÿ��� ���Ѵ�.

�ذ� ��� : ���� ������ ���� ����, ȸ���ϴ� Ķ���۽� �˰����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, ���� ����, ȸ���ϴ� Ķ���۽�
*/

typedef struct point {
    long long x, y;
} point;

point arrow[103000], cvh[103000];
long long sx, sy;

long long dist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1;
    else if (tri == 0) return 0;
    else return -1;
}

point vecmove(point p1, point p2, point p3) {
    //p1->p2�� ���ϴ� ������ �������� p3���� �Ű��� ���� ������ ����
    point res = { 0, 0 };
    res.x = p2.x - p1.x + p3.x;
    res.y = p2.y - p1.y + p3.y;
    return res;
}

int cmp_points(const void* a, const void* b) {
    //�� ���� ������(sx, sy)�� �������� ������.
    long long ax = (*(point*)a).x;
    long long ay = (*(point*)a).y;
    long long bx = (*(point*)b).x;
    long long by = (*(point*)b).y;
    int ar, br;
    if (ax == sx) ar = 0;
    else if (ay > sy) ar = 1;
    else if (ay == sy) ar = 2;
    else ar = 3;
    if (bx == sx) br = 0;
    else if (by > sy) br = 1;
    else if (by == sy) br = 2;
    else br = 3;
    if (ar != br) return ar > br ? 1 : -1;
    if (ar == 0 && br == 0) return ay > by ? 1 : ay == by ? 0 : -1;
    if (ar == 2 && br == 2) return ax > bx ? 1 : ax == bx ? 0 : -1;

    long long res = (ax - sx) * (by - sy) - (ay - sy) * (bx - sx);
    return res > 0 ? 1 : res == 0 ? 0 : -1;
}

int get_convex_hull(point* cvh_pts, point* cvh_stk, int n) {
    //���� ������ cvh_stk�� ����� �� ũ�⸦ ��ȯ��.
    int sel = 0; //���� ������ ������
    int ccw_num = 0; //ccw��
    int cvh_top = 2; //���� ������ �̷�� �� ����(�ּ� 2��)
    for (int i = 0; i < n; i++) {
        if (cvh_pts[i].x < cvh_pts[sel].x ||
            (cvh_pts[i].x == cvh_pts[sel].x && cvh_pts[i].y < cvh_pts[sel].y)) {
            sel = i;
        }
    }

    sx = cvh_pts[sel].x; //�������� ��ǥ�� ���� ������ ����
    sy = cvh_pts[sel].y;
    qsort(cvh_pts, n, sizeof(point), cmp_points); //��� ������ �������� ���� ���� ������ ����

    cvh_stk[0] = cvh_pts[0];
    if (n == 1) return 1; //n == 1�� ��쿡 ���� ���� ó��
    cvh_stk[1] = cvh_pts[1]; //ù �� ���� ����
    for (int i = 2; i <= n; i++) {
        //�������� ���� ���� ���������� ���ϲ��� ����
        cvh_stk[cvh_top++] = (i == n ? cvh_pts[0] : cvh_pts[i]);
        ccw_num = ccw(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2], cvh_stk[cvh_top - 1]);
        while (cvh_top > 2 && ccw_num >= 0) {
            //�ֱ� 3�� ������ ������ �ݴ��� ��� ���ÿ��� ����
            if (ccw_num == 0 && dist(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2]) >
                dist(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 1])) {
                //������ ���� �� �տ� �ִ� ���� ���� ��� �ش� �� ����
                if (i == n) break; //���п� ���� ���� ó��
                cvh_top--;
                if (cvh_top > 2) {
                    ccw_num = ccw(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2], cvh_stk[cvh_top - 1]);
                }
                continue;
            }
            cvh_top -= 2;
            cvh_stk[cvh_top++] = (i == n ? cvh_pts[0] : cvh_pts[i]);
            if (cvh_top > 2) {
                ccw_num = ccw(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2], cvh_stk[cvh_top - 1]);
            }
        }
    }
    cvh_top--;
    return cvh_top;
}

long long rotating_calipers(point* cvh, int n) {
    //���� �������� ���� �� �� ���� ���Ѵ�.

    //baseline: 0�� ��� �Ʒ�, 1�� ��� ������ ���ؼ�, lower: �Ʒ����� ������, upper: ������ ������
    int lower = 0, upper = 0, res = 0, baseline = 0, finished = 0;


    if (n == 1) return 0;
    else if (n == 2) return dist(cvh[0], cvh[1]);


    while (ccw(vecmove(cvh[1], cvh[0], cvh[upper]), cvh[upper], cvh[(upper + 1) % n]) <= 0) {
        upper = (upper + 1) % n;
    }
    while (!finished || lower == 0) {
        if (baseline && dist(cvh[lower], cvh[(upper + 1) % n]) > res) {
            res = dist(cvh[lower], cvh[(upper + 1) % n]);
        }
        if (!baseline && dist(cvh[(lower + 1) % n], cvh[upper]) > res) {
            res = dist(cvh[(lower + 1) % n], cvh[upper]);
        }

        if (baseline) {
            if (ccw(vecmove(cvh[(lower + 1) % n], cvh[lower], cvh[(upper + 1) % n]),
                cvh[(upper + 1) % n], cvh[(upper + 2) % n]) >= 0) {
                //�Ʒ����� �̵�, ��, �������� ������ ����
                upper = (upper + 1) % n;
                baseline = 0;
            }
            else {
                //������ �̵�
                upper = (upper + 1) % n;
            }
        }
        else {
            if (ccw(vecmove(cvh[(upper + 1) % n], cvh[upper], cvh[(lower + 1) % n]),
                cvh[(lower + 1) % n], cvh[(lower + 2) % n]) >= 0) {
                //������ �̵�, ��, �������� �Ʒ����� ����
                lower++;
                if (lower == n) {
                    finished = 1;
                    lower -= n;
                }
                baseline = 1;
            }
            else {
                //�Ʒ����� �̵�
                lower++;
                if (lower == n) {
                    finished = 1;
                    lower -= n;
                }
            }
        }
    }
    return res;
}

int main(void) {
    int n, sz;
    long long res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &arrow[i].x, &arrow[i].y);
    }
    sz = get_convex_hull(arrow, cvh, n);
    res = rotating_calipers(cvh, sz);
    printf("%lld", res);
    return 0;
}