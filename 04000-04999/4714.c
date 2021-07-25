#include <stdio.h>

/*
문제 : 지구에서 무게 X인 물건이 달에서는 무게가 얼마인지 구한다. 달의 중력은 지구 중력의 0.167배이다.

해결 방법 : X에 0.167배를 곱하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : MidAt 2010 P번
*/

int main(void) {
    double x;
    while (1) {
        scanf("%lf", &x);
        if (x < -0.5) break;
        printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", x, x * 0.167);
    }
    return 0;
}