#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : 평면상에 N(N <= 100)개의 선분 모양의 노선이 있다. 각 노선은 자사 또는 타사 노선이며,
지상 또는 지하로 이어진다. 이때, 두 점 A에서 B로 이동하는 노선을 지으며 만들어야 하는
지상과 지하를 잇는 통로의 개수를 구한다. 만나는 노선마다 자사 노선과는 같은 높이,
타사 노선과는 다른 높이에 지어져야 한다.
각 노선의 시작점, 끝점의 위치는 [-10000, 10000] 범위의 정수이다. 또한, 두 노선은 겹치지 않고
한 점에서 여러 노선과 만나거나 매우 가까운(10^-9 이내) 범위에서 여러 노선과 만나지 않는다.

해결 방법 : 각 이미 지어진 노선마다 새로운 노선과 교차하는 지 여부를 확인한다.
두 노선이 교차하는 경우 두 노선의 교점을 구한다. 교점을 구한 다음, 노선의 높이를 확인하고
배열에 집어넣는다. 그 다음 배열에서 값들을 순서대로 정렬하고, 인접한 위치에 서로 다른 높이인
지점들의 개수를 세면 답이 된다.

주요 알고리즘 : 수학, 기하학, 선분 교차, 케이스 워크, 정렬

출처 : JAG 2006D D번
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