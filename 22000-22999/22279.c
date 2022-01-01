#include <stdio.h>

/*
문제 : 삶의 N(N <= 100)개의 구간에 대해 삶의 질(0 <, <= 1, 실수)과 기간(0 <, <= 100, 실수)이 주어질 때,
삶의 질을 반영한 수명을 구한다.

해결 방법 : 모든 구간의 삶의 질 * 기간을 더한 값을 구하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : Rocky 2018 A번
*/

int main(void) {
    int n;
    double q, y, r = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &q, &y);
        r += q * y;
    }
    printf("%f", r);
    return 0;
}