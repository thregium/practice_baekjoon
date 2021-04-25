#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : 세 점의 좌표가 주어질 때 한 점을 추가해서 만들 수 있는 평행사변형 중 가장 둘레가 긴 것과 가장 둘레가 짧은 것의 둘레 차를 구한다.
단, 주어진 좌표로는 평행사변형을 만들 수 없는 경우 -1을 출력한다.

해결 방법 : 한 점을 추가해서 평행사변형을 만들 수 없는 경우는 세 점이 직선상에 놓이는 경우이다.
CCW를 이용하거나 가장 긴 선분이 나머지 두 선분과 길이가 같음을 이용해서 알 수 있다.
평행사변형의 둘레는 한 꼭짓점에서 이어진 두 선분 길이의 합 * 2이므로 가장 긴 것과 가장 짧은 것은 (긴 변 + 중간 변 - (중간 변 + 짧은 변)) * 2
= (긴 변 - 짧은 변) * 2이 된다. 각 선분의 길이는 피타고라스의 정리를 이용해 계산한다.

주요 알고리즘 : 기하학, 피타고라스의 정리
*/

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int xa, ya, xb, yb, xc, yc;
    double l[3];
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    if (xa * yb + xb * yc + xc * ya - (xb * ya + xc * yb + xa * yc) == 0) printf("-1"); //직선상에 있는 경우
    else {
        l[0] = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
        l[1] = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
        l[2] = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
        qsort(l, 3, sizeof(double), cmp1);
        printf("%.15lf", (l[2] - l[0]) * 2);
    }
    return 0;
}