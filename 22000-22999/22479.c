#include <stdio.h>

/*
문제 : 볼록 N(N <= 50)각형이 주어질 때, 이 도형의 특정 점에서 2번 자를 때, 마주보는 두 잘린 도형의 크기가
같게 되는 점이 있는 지 구하고, 있다면 그 점을 출력한다. 점의 좌표는 절댓값 10^6 이하의 정수이다.

해결 방법 : 홀수 각형인 경우 조건을 만족할 수 없음을 간단히 알 수 있다. 짝수 각형인 경우에는
마주보는 두 변이 평행하고 길이가 같아야만 조건을 만족하게 된다. 그렇지 않으면 마주보는 두 선분으로
선분을 그었을 때 넓이가 일정하지 않게 되기 때문에 조건을 만족할 수 없다.
조건을 만족하는 경우 그 점의 좌표는 마주보는 두 꼭짓점의 중점과 같다.

주요 알고리즘 : 기하학

출처 : JAG 2012S3B C번
*/

long long point[64][2];

long long sqr(long long x) {
    return x * x;
}

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    if (n & 1) {
        printf("NA\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &point[i][0], &point[i][1]);
    }
    point[n][0] = point[0][0], point[n][1] = point[0][1];
    for (int i = 0, j = (n >> 1); j < n; i++, j++) {
        if (sqr(point[i][0] - point[i + 1][0]) + sqr(point[i][1] - point[i + 1][1])
            != sqr(point[j][0] - point[j + 1][0]) + sqr(point[j][1] - point[j + 1][1])) r = 0;
        if ((point[i][0] - point[i + 1][0]) * (point[j][1] - point[j + 1][1]) !=
            (point[j][0] - point[j + 1][0]) * (point[i][1] - point[i + 1][1])) r = 0;
    }
    if (r) printf("%.9f %.9f\n", (point[0][0] + point[n >> 1][0]) / 2.0,
        (point[0][1] + point[n >> 1][1]) / 2.0);
    else printf("NA\n");
    return 0;
}