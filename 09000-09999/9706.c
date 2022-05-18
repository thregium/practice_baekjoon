#include <stdio.h>

/*
���� : N(1 < N < 100)���� ���� ��ǥ���� �ִ�. �̶�, ���� ���� ���� ������ ������ ������
���� ������ ���Ѵ�. ���� ��ġ�� ���� �־����� �ʴ´�.

�ذ� ��� : ��� ���� �ֿ� ���� �ش� �� ���� ������ ������ �ִ� ���� ������ CCW�� �̿��� ����.
�� �� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������, CCW, ���Ʈ ����

��ó : Khwarizmi 2012 D��
*/

typedef struct point {
    long long x, y;
} point;

point p[128];

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1;
    else if (tri == 0) return 0;
    else return -1;
}

int main(void) {
    int t, n, r, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        r = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                c = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        c++;
                        continue;
                    }
                    else if (ccw(p[i], p[j], p[k]) == 0) c++;
                }
                if (c > r) r = c;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}