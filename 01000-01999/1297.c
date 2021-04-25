#include <stdio.h>
#include <math.h>

/*
문제 : 직사각형의 대각선 길이와 높이, 너비 비율이 주어질 때, 실제 높이와 너비를 출력한다.

해결 방법 : 대각선 길이와 높이와 너비 비율을 바탕으로 실제 높이나 너비와의 배율을 구한 뒤, 주어진 비율에 곱해 출력한다.

주요 알고리즘 : 수학, 기하학
*/

int main(void) {
    int d, h, w;
    double x;
    scanf("%d %d %d", &d, &h, &w);
    x = d / sqrt((h * h + w * w));
    printf("%d %d", (int)(x * h), (int)(x * w));
    return 0;
}