#include <stdio.h>

/*
문제 : P명이 H개의 핫도그를 먹었을 때, 1인당 평균 몇개 먹은 것인지를 구한다.

해결 방법 : H / P개이므로 이를 계산해 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : Latin 2012 PA번
*/

int main(void) {
    double h, p;
    while (scanf("%lf %lf", &h, &p) != EOF) {
        printf("%.2f\n", h / p);
    }
    return 0;
}