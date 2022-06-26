#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 점이 좌표평면상에 있다. 각 점은 검은색과 흰색으로 나누니다.
이때, 직선을 그어서 한쪽에는 검은 점만 오도록 할 때, 그 검은 색 점의 최대 개수를 구한다.
어떤 3개의 점도 같은 직선상에 있지 않다.

해결 방법 : 모든 2개의 점의 쌍에 대해 양쪽에 해당하는 각 색의 점 개수를 구한다.
어느 방향인지는 CCW를 이용하면 간단히 구할 수 있다.
만약 한쪽에 흰 점이 없다면 그 방향의 검은 점 개수(+ 기준점의 검은 점 개수)의 합이 답이 된다.

주요 알고리즘 : 기하학, 브루트 포스

출처 : 아주대 2017D1 G1번
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