#include <stdio.h>
#include <math.h>

/*
문제 : 직사각형의 가로와 세로 길이가 주어질 때, 가로와 세로 길이의 합에서 대각선 길이를 뺀 값을 구한다.

해결 방법 : 피타고라스 정리를 이용해 대각선 길이를 구하고 가로 세로의 합에서 뺀다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : BAPC 2020P C번
*/

int main(void) {
    int w, h;
    scanf("%d %d", &w, &h);
    printf("%.9lf", (w + h) - sqrt(w * w + h * h));
    return 0;
}