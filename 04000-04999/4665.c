#include <stdio.h>
#include <stdlib.h>

/*
���� : N(4 <= N <= 15)���� ���� �־��� ��, ����(�𼭸� ����)�� �ٸ� ���� ���� ���� ū �ﰢ���� ���Ѵ�.
�̷��� �ﰢ���� �ݵ�� �����ϵ��� �־�����.

�ذ� ��� : ������ ��� �ﰢ���� ���� ���ο� ���� ������ �˻��Ѵ�. ��� ���� �ﰢ���� �� ���а� CCW�� �� �����
��� ���� ��ȣ�� ��� �ﰢ���� ���ο� �ִ� ���̴�. ����, �� ���� ��� �ϳ��� ���ο� �ִ� ��쿡��
�𼭸��� �ִ� ���̹Ƿ� �ﰢ���� ���ο� �ִ� ���̴�. �ﰢ���� ���̴� ������ �־������ ���ϸ� �ȴ�.
���ο� ���� ���� �ﰢ�� ��� �� ���� ���� Ŀ���� ��츦 ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, �ٰ��� ������ �� ����, ���Ʈ ����

��ó : MidC 1999 B��
*/

typedef struct point {
    int x;
    int y;
    char c;
} point;

char bres[4];
point pt[16];

int cmp1(const void* a, const void* b) {
    char ai = ((point*)a)->c;
    char bi = ((point*)b)->c;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getsign(int x) {
    if (x < 0) return -1;
    else if (x == 0) return 0;
    else return 1;
}

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int inside(int ax, int ay, int bx, int by, int cx, int cy) {
    if (ccw(ax, ay, bx, by, cx, cy)) return 0;
    if (((cx >= ax && cx <= bx) || (cx <= ax && cx >= bx)) && ((cy >= ay && cy <= by) || (cy <= ay && cy >= by))) return 1;
    else return 0;
}

int main(void) {
    int n, best, cnt, mon;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf(" %c %d %d", &pt[i].c, &pt[i].x, &pt[i].y);
        }
        qsort(pt, n, sizeof(point), cmp1);

        best = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    mon = 0;
                    for (int l = 0; l < n; l++) {
                        if (l == i || l == j || l == k) continue;
                        if (getsign(ccw(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[l].x, pt[l].y)) ==
                            getsign(ccw(pt[j].x, pt[j].y, pt[k].x, pt[k].y, pt[l].x, pt[l].y)) &&
                            getsign(ccw(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[l].x, pt[l].y)) ==
                            getsign(ccw(pt[k].x, pt[k].y, pt[i].x, pt[i].y, pt[l].x, pt[l].y))) {
                            mon = 1;
                            break;
                        }
                        if (inside(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[l].x, pt[l].y) ||
                            inside(pt[j].x, pt[j].y, pt[k].x, pt[k].y, pt[l].x, pt[l].y) ||
                            inside(pt[k].x, pt[k].y, pt[i].x, pt[i].y, pt[l].x, pt[l].y)) {
                            mon = 1;
                            break;
                        }
                    }
                    if (mon) continue;

                    if (abs(ccw(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y)) > best) {
                        best = abs(ccw(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y));
                        bres[0] = pt[i].c, bres[1] = pt[j].c, bres[2] = pt[k].c;
                        cnt = 1;
                    }
                    else if (abs(ccw(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y)) == best) cnt++;
                }
            }
        }
        if (best < 0 || cnt > 1) return 1;
        printf("%s\n", bres);
    }
    return 0;
}