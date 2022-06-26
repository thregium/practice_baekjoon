#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI acos(-1)

/*
문제 : N(3 <= N <= 300000)개의 점(|X|, |Y| <= 10^6, 자연수)으로 이루어진 단순 다각형이 좌표평면상에 있다.
이 다각형은 원점을 포함하고, 어떤 세 점도 일직선상에 있지 않다.
이때, 이 다각형을 반시계방향으로 돌려서 자취를 원형으로 만들기 위해 돌려야 하는 최소 각도를 구한다.

해결 방법 : 우선 원점에서 가장 멀리 떨어진 점들만을 찾는다.
그 다음, 각 점의 각도를 atan2 함수를 이용해 구해준다. 이 값들을 정렬한 다음 인접한 수와의 차이의
최댓값을 구하면 된다. 단, 시작과 끝점 사이도 확인해야 한다.

주요 알고리즘 : 기하학

출처 : 서울대 2018D2 D번
*/

typedef struct point {
    long long x, y;
} point;

point pt[327680];
double ang[327680];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

long long getdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
    int n, acnt = 0;
    long long mdist = 0;
    double res = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pt[i].x, &pt[i].y);
        if (getdist(pt[i], (point) { 0, 0 }) > mdist) mdist = getdist(pt[i], (point) { 0, 0 });
    }
    for (int i = 0; i < n; i++) {
        if (pt[i].x == 0 && pt[i].y == 0) continue;
        if (getdist(pt[i], (point) { 0, 0 }) == mdist) {
            ang[acnt++] = atan2(pt[i].y, pt[i].x) / PI * 180.0;
        }
    }
    qsort(ang, acnt, sizeof(double), cmp1);
    for (int i = 1; i < acnt; i++) {
        if (ang[i] - ang[i - 1] > res) res = ang[i] - ang[i - 1];
    }
    if (ang[0] - ang[acnt - 1] + 360.0 > res) res = ang[0] - ang[acnt - 1] + 360.0;
    printf("%.9f", res);
    return 0;
}