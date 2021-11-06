#include <stdio.h>

/*
문제 : 두 직사각형의 좌표 범위가 10^6 이하의 음이 아닌 정수로 주어질 때, 두 직사각형이 겹치는 넓이를 구한다.

해결 방법 : X좌표의 최댓값과 최솟값, Y좌표의 최댓값과 최솟값을 각각 구한다. 그 다음, 최댓값에서 최솟값을 뺀 것을
해당 변의 길이로 두되, 음수인 경우 0으로 바꾼다. 그 다음, 두 변의 길이의 곱을 구하면 된다.
오버플로우와 Y좌표에 유의한다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : ILOCAMP 2010B 2-3번
*/

int main(void) {
    long long x1, y1, x2, y2, x3, y3, x4, y4, h, w;
    scanf("%lld %lld %lld %lld%lld %lld %lld %lld", &x1, &y2, &x2, &y1, &x3, &y4, &x4, &y3);
    if (x3 > x1) x1 = x3;
    if (y3 > y1) y1 = y3;
    if (x4 < x2) x2 = x4;
    if (y4 < y2) y2 = y4;
    h = y2 - y1;
    if (h < 0) h = 0;
    w = x2 - x1;
    if (w < 0) w = 0;
    printf("%lld", h * w);
    return 0;
}