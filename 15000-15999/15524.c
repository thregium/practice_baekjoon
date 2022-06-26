#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 16)개의 동전의 반지름과 현 위치, 목표 위치가 주어진다.
이때, 동전들을 하나씩 직선으로 이동시킨다면 동전끼리 부딪히지 않고 옮길 수 있는 동전의 최대 개수를 구한다.
각 동전은 처음에 전부 따로 떨어져 있으며, 현 위치와 목표 위치는 다르다.

해결 방법 : 비트마스킹 DP로 각 동전의 이동 상태를 저장해 나가면서 이동할 수 있는 동전들을 이동시켜 보고,
그 중 가장 많은 동전들이 이동된 상태의 이동된 동전 개수를 세면 된다.
이동할 수 있는 동전인지 여부는 경로를 직사각형 부분과 두 원 부분 이렇게 세 부분으로 나누어
각 다른 동전들에 대해 서로 겹치는 경우가 없는 지 확인해 주면 된다.

주요 알고리즘 : DP, 비트DP, 기하학

출처 : JAG 2017P G번
*/

typedef struct point {
    double x, y;
} point;

char mem[65536];
point pts[16][2];
double rad[16];

int ccw(point p1, point p2, point p3) {
    double tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0.0000001) return 1;
    else if (tri > -0.0000001) return 0;
    else return -1;
}

double sqr(double x) {
    return x * x;
}

double getdist(point p1, point p2) {
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

point pplus(point p1, point p2) {
    return (point) { p1.x + p2.x, p1.y + p2.y };
}
point pminus(point p1, point p2) {
    return (point) { p1.x - p2.x, p1.y - p2.y };
}
point pmult(point p1, double m) {
    return (point) { p1.x * m, p1.y * m };
}

int main(void) {
    int n, ok, res = 0, pcnt;
    point pos, vec;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf", &rad[i], &pts[i][0].x, &pts[i][0].y, &pts[i][1].x, &pts[i][1].y);
    }
    mem[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        if (!mem[i]) continue;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            ok = 1;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                else if ((i >> k) & 1) pos = pts[k][1];
                else pos = pts[k][0];

                vec = (point){ (pts[j][0].y - pts[j][1].y) / getdist(pts[j][0], pts[j][1]),
                    (pts[j][1].x - pts[j][0].x) / getdist(pts[j][0], pts[j][1]) };

                if (ccw(pplus(pts[j][0], pmult(vec, rad[j])), pplus(pts[j][1], pmult(vec, rad[j])),
                    pplus(pos, pmult(vec, rad[k]))) *
                    ccw(pminus(pts[j][0], pmult(vec, rad[j])), pminus(pts[j][1], pmult(vec, rad[j])),
                        pplus(pos, pmult(vec, rad[k]))) <= 0) {
                    if (ccw(pts[j][0], pplus(pts[j][0], vec), pos) *
                        ccw(pts[j][1], pplus(pts[j][1], vec), pos) <= 0) {
                        ok = 0;
                    }
                }
                if (ccw(pplus(pts[j][0], pmult(vec, rad[j])), pplus(pts[j][1], pmult(vec, rad[j])),
                    pminus(pos, pmult(vec, rad[k]))) *
                    ccw(pminus(pts[j][0], pmult(vec, rad[j])), pminus(pts[j][1], pmult(vec, rad[j])),
                        pminus(pos, pmult(vec, rad[k]))) <= 0) {
                    if (ccw(pts[j][0], pplus(pts[j][0], vec), pos) *
                        ccw(pts[j][1], pplus(pts[j][1], vec), pos) <= 0) {
                        ok = 0;
                    }
                }
                
                if (ccw(pplus(pts[j][0], pmult(vec, rad[j])), pplus(pts[j][1], pmult(vec, rad[j])),
                    pos) *
                    ccw(pminus(pts[j][0], pmult(vec, rad[j])), pminus(pts[j][1], pmult(vec, rad[j])),
                        pos) <= 0) {
                    if (ccw(pts[j][0], pplus(pts[j][0], vec), pos) *
                        ccw(pts[j][1], pplus(pts[j][1], vec), pos) <= 0) {
                        ok = 0;
                    }
                }
                if (ccw(pts[j][0], pts[j][1], pplus(pos, pmult(vec, rad[k]))) *
                    ccw(pts[j][0], pts[j][1], pminus(pos, pmult(vec, rad[k]))) <= 0) {
                    if (ccw(pts[j][0], pplus(pts[j][0], vec), pos) *
                        ccw(pts[j][1], pplus(pts[j][1], vec), pos) <= 0) {
                        ok = 0;
                    }
                }
                


                if (getdist(pos, pts[j][0]) <= rad[j] + rad[k] + 0.000001) ok = 0;
                if (getdist(pos, pts[j][1]) <= rad[j] + rad[k] + 0.000001) ok = 0;
                /*
                if (getdist(pos, pplus(pts[j][0], pmult(vec, rad[j]))) <= rad[j]) ok = 0;
                if (getdist(pos, pminus(pts[j][0], pmult(vec, rad[j]))) <= rad[j]) ok = 0;
                if (getdist(pos, pplus(pts[j][1], pmult(vec, rad[j]))) <= rad[j]) ok = 0;
                if (getdist(pos, pminus(pts[j][1], pmult(vec, rad[j]))) <= rad[j]) ok = 0;
                */
            }
            if (ok) {
                mem[i ^ (1 << j)] = 1;
            }
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        if (!mem[i]) continue;
        pcnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) pcnt++;
        }
        if (pcnt > res) res = pcnt;
    }
    printf("%d\n", res);
    return 0;
}