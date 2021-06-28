#include <stdio.h>

/*
문제 : 출생 연도의 범위와 사망 연도의 범위가 주어질 때, 가능한 사망 연령의 최솟값과 최댓값을 구한다.

해결 방법 : 최솟값은 가장 늦게 태어나서 가장 일찍 죽는 경우이고, 최댓값은 가장 일찍 태어나서 가장 늦게 죽는 경우이다.

주요 알고리즘 : 수학, 사칙연산

출처 : Tehran 2014 A번
*/

int main(void) {
    int a, b, c, d;
    while (1) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        printf("%d %d\n", c - b, d - a);
    }
    return 0;
}