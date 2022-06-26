#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 2000)���� ���� �ٸ� ��(|| <= 10000)�� ��ǥ���� �־��� ��, �� ������ �̿��Ͽ�
���� �ܼ� �ٰ����� ����Ѵ�. ��� ���� ������ �ִ� ���� ����.

�ذ� ��� : �������� ���� ���� �������� ���� ���� ����->����� ������� �����ϰ�, �� ������ ����Ѵ�.
��, �������� ���ƿ� ������ �� ������� ���ƿ;� �ϹǷ� �� �κп��� ���� ó���� �ʿ��ϴ�.

�ֿ� �˰��� : ������, ����

��ó : NWERC 2009 I��
*/

typedef struct point {
    long long x, y;
    int idx;
} point;

point pt[2048];
long long sx, sy;

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

void swap(point* p1, point* p2) {
    point p3 = *p1;
    *p1 = *p2;
    *p2 = p3;
}

long long getdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
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
    if (res != 0) return res > 0 ? 1 : -1;
    ar = getdist((point) { ax, ay }, (point) { sx, sy });
    br = getdist((point) { bx, by }, (point) { sx, sy });
    return ar > br ? 1 : ar == br ? 0 : -1;
}

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1;
    else if (tri == 0) return 0;
    else return -1;
}

int dotinline(point p1, point p2, point p3) {
    if (ccw(p1, p2, p3)) return 0;
    if (p3.x > big(p1.x, p2.x) || p3.x < small(p1.x, p2.x) || p3.y > big(p1.y, p2.y) || p3.y < small(p1.y, p2.y)) return 0;
    else return 1;
}

int equalline(point p1, point p2, point p3, point p4) {
    if ((dotinline(p1, p2, p3) && dotinline(p1, p2, p4)) || (dotinline(p3, p4, p1) && dotinline(p3, p4, p2))) return 1;
    return 0;
}

int crossline(point p1, point p2, point p3, point p4) {
    if (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0) return 1;
    else if (ccw(p1, p2, p3) * ccw(p1, p2, p4) && ccw(p3, p4, p1) * ccw(p3, p4, p2)) return 0;
    if (dotinline(p1, p2, p3) || dotinline(p1, p2, p4) || dotinline(p3, p4, p1) || dotinline(p3, p4, p2)) return 1;
    else return 0;
}

int main(void) {
    int t, n, sel, ok, stolt;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2009\\testdata\\I.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        sel = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &pt[i].x, &pt[i].y);
            pt[i].idx = i;
            if (pt[i].x < pt[sel].x || (pt[i].x == pt[sel].x && pt[i].y < pt[sel].y)) {
                sel = i;
            }
        }
        sx = pt[sel].x; //�������� ��ǥ�� ���� ������ ����
        sy = pt[sel].y;
        qsort(pt, n, sizeof(point), cmp_points); //��� ������ �������� ���� ���� ������ ����

        stolt = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if ((pt[i + 1].x - sx) * (pt[i].y - sy) == (pt[i + 1].y - sy) * (pt[i].x - sx)) stolt = i;
            else break;
        }
        for (int i = stolt, j = n - 1; i < j; i++, j--) {
            swap(&pt[i], &pt[j]);
        }

        ok = 1;
        /*
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (i == 0 && j == n - 1) continue;
                if (crossline(pt[i], pt[i + 1], pt[j], pt[(j + 1) % n])) ok = 0;
            }
        }
        */
        if (!ok) {
            printf("Error at TC %d\n", tt + 1);
            return 1;
        }
        else {
            for (int i = 0; i < n; i++) {
                printf("%d ", pt[i].idx);
            }
            printf("\n");
        }
    }
    return 0;
}