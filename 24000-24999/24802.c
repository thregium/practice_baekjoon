#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
문제 : A(A <= 5000)개의 올라가는 구간과 D(D <= 5000)개의 내려가는 구간이 주어진다.
각 구간의 높이는 1000 이하의 음이 아닌 정수고, 거리는 100 이하의 자연수이다. 이때, 두 선이 겹치는
가장 왼쪽 점의 거리를 구한다.

해결 방법 : 모든 올라가는 구간과 내려가는 구간을 선분으로 바꾼 다음, 모든 쌍에 대해
두 선이 겹치는 가장 왼쪽 위치를 찾으면 된다.

주요 알고리즘 : 브루트 포스, 기하학, 선분 교차

출처 : VTH 2017 J번
*/

typedef struct point {
    long long int x;
    long long int y;
} point;

typedef struct pointf {
    double x;
    double y;
} pointf;

point asc[5120], desc[5120];

long long int big(long long a, long long b) {
    return a > b ? a : b;
}

long long int small(long long a, long long b) {
    return a < b ? a : b;
}

int equalpoint(point p1, point p2) {
    if (p1.x == p2.x && p1.y == p2.y) return 1;
    else return 0;
}

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
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

pointf getcrosspoint(point p1, point p2, point p3, point p4) {
    pointf res = { 0, 0 };
    double d1, d2, in1, in2, x, y;
    if (!ccw(p1, p2, p3) && !ccw(p1, p2, p4)) {
        if (equalline(p1, p2, p3, p4)) {
            res.x = p1.x, res.y = big(p1.y, p3.y);
        }
        else if (equalpoint(p1, p3) || equalpoint(p1, p4)) {
            res.x = p1.x, res.y = p1.y;
        }
        else if (equalpoint(p2, p3) || equalpoint(p2, p4)) {
            res.x = p2.x, res.y = p2.y;
        }
    }
    else {
        if (p1.x != p2.x && p3.x != p4.x) {
            d1 = (p2.y - p1.y) / (double)(p2.x - p1.x);
            d2 = (p4.y - p3.y) / (double)(p4.x - p3.x);
            in1 = p1.y - p1.x * d1;
            in2 = p3.y - p3.x * d2;
            x = (in1 - in2) / (d2 - d1);
        }
        else if (p1.x != p2.x) {
            d1 = (p2.y - p1.y) / (double)(p2.x - p1.x);
            in1 = p1.y - p1.x * d1;
            x = p3.x;
        }
        else {
            d1 = (p4.y - p3.y) / (double)(p4.x - p3.x);
            in1 = p3.y - p3.x * d1;
            x = p1.x;
        }
        y = x * d1 + in1;
        res.x = x, res.y = y;
    }
    return res;
}

int main(void) {
    pointf res = { 0, 1E+18 };
    int a, d, h, t, hs = 0, ts = 0;
    scanf("%d %d", &a, &d);
    for (int i = 1; i <= a; i++) {
        scanf("%d %d", &h, &t);
        hs += h, ts += t;
        asc[i].x = hs, asc[i].y = ts;
    }
    ts = 0;
    desc[0].x = hs;
    for (int i = 1; i <= d; i++) {
        scanf("%d %d", &h, &t);
        hs -= h, ts += t;
        desc[i].x = hs, desc[i].y = ts;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < d; j++) {
            if (crossline(asc[i], asc[i + 1], desc[j], desc[j + 1])) {
                if (getcrosspoint(asc[i], asc[i + 1], desc[j], desc[j + 1]).y < res.y) {
                    res = getcrosspoint(asc[i], asc[i + 1], desc[j], desc[j + 1]);
                }
            }
        }
    }
    printf("%.9f", res.y);

    return 0;
}