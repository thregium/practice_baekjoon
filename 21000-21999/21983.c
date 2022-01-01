#include <stdio.h>
#include <math.h>

/*
문제 : 넓이가 A(1 <= A <= 10^18)인 정육각형의 둘레를 구한다.

해결 방법 : A의 제곱근에 192의 제곱근의 제곱근을 곱하면 된다.

주요 알고리즘 : 수학, 기하학

출처 : NWERC 2021 PB번
*/

int main(void) {
    double a;
    scanf("%lf", &a);
    printf("%.9f", sqrt(a) * sqrt(sqrt(192)));
    return 0;
}