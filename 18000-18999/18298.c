#include <stdio.h>

/*
문제 : N(N <= 1000)개의 P_i(P_i <= 50)각 다각형의 넓이 합을 구한다. 각 다각형은 단순 다각형이며,
서로 겹치지 않는다.

해결 방법 : 각 다각형의 넓이를 구하고 전부 더한 다음 2로 나누면 된다.

주요 알고리즘 : 기하학, 다각형의 넓이

출처 : SWERC 2019 F번
*/

typedef struct point {
    long long x, y;
} point;

point poly[64];

long long getarea(point* poly, int n) {
    //N각 다각형의 넓이(*2)를 구해줌
    long long area = 0;
    for (int i = 0; i < n - 1; i++) {
        area += poly[i].x * poly[i + 1].y;
        area -= poly[i + 1].x * poly[i].y;
    }
    area += poly[n - 1].x * poly[0].y;
    area -= poly[0].x * poly[n - 1].y;

    if (area < 0) area *= -1;
    return area;
}

int main(void) {
    int n, p;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        for (int j = 0; j < p; j++) {
            scanf("%lld %lld", &poly[j].x, &poly[j].y);
        }
        r += getarea(poly, p);
    }
    printf("%lld", r >> 1);
    return 0;
}