#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 100)개의 120도 단위 이동으로 이루어진 단순 다각형이 주어질 때,
이 다각형에 포함되는 단위 삼각형의 개수를 구한다. 이 다각형의 둘레는 1000 이하다.

해결 방법 : 주어진 다각형의 꼭짓점들을 찾은 다음, 그 위치를 이용해 그 도형의 넓이를 구한다.
그 넓이를 단위 삼각형의 크기로 나눈 것을 반올림하면 답이 된다.

주요 알고리즘 : 기하학, 다각형의 넓이, 시뮬레이션

출처 : BAPC 2015P C번
*/

typedef struct fpoint {
    double x, y;
} fpoint;

fpoint pt[128];

double getfarea(fpoint* poly, int n) {
    //N각 다각형의 넓이를 구해줌
    double area = 0;
    for (int i = 0; i < n - 1; i++) {
        area += poly[i].x * poly[i + 1].y;
        area -= poly[i + 1].x * poly[i].y;
    }
    area += poly[n - 1].x * poly[0].y;
    area -= poly[0].x * poly[n - 1].y;

    if (area < 0) area *= -1;
    return area / 2.0;
}

int main(void) {
    int t, n, l;
    double x, y, res;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        x = 0.0, y = 0.0;
        pt[0].x = x, pt[0].y = y;
        for (int i = 1; i <= n; i++) {
            scanf(" %c %d", &c, &l);
            if (c == 'x') x += l;
            else if (c == 'y') {
                x += l / 2.0;
                y += l / 2.0 * sqrt(3);
            }
            else if (c == 'z') {
                x -= l / 2.0;
                y += l / 2.0 * sqrt(3);
            }
            else return 1;
            pt[i].x = x, pt[i].y = y;
        }

        res = getfarea(pt, n + 1);
        printf("%.0f\n", round(res / sqrt(3) * 4.0));
    }
    return 0;
}