#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
문제 : 원의 넓이가 주어질 때 원의 둘레를 구한다.

해결 방법 : 원의 넓이에서 파이를 나누고 제곱근을 하면 반지름이 나온다. 여기서 2파이를 곱하면 둘레가 된다.

주요 알고리즘 : 기하학, 수학

출처 : NWERC 2019 PC번
*/

int main(void) {
    long long a;
    scanf("%lld", &a);
    printf("%.16lf", sqrt(a / PI) * PI * 2);
    return 0;
}