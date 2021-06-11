#include <stdio.h>
#include <math.h>

/*
문제 : 넓이 A(A <= 10^18)가 되는 사각형의 둘레를 가능한 짧게 할 때의 둘레를 구한다.

해결 방법 : 해당 경우는 정사각형일 때이고, sqrt(A)에 4를 곱하면 둘레가 된다.

주요 알고리즘 : 기하학, 수학

출처 : NWERC 2016 PA번
*/

int main(void) {
    long long a;
    scanf("%lld", &a);
    printf("%.16lf", sqrt(a) * 4);
    return 0;
}