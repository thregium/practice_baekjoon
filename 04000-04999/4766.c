#include <stdio.h>

/*
문제 : 999가 나올 때 까지 현재 값과 이전 값 사이의 차이를 구한다.

해결 방법 : 마지막 값을 저장해두며 현재 값과의 차이를 계속해서 구하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : MidA 2002 A번 / 2003 P번
*/

int main(void) {
    double t, l;
    scanf("%lf", &t);
    l = t;
    while (1) {
        scanf("%lf", &t);
        if (t > 250) break;
        printf("%.2f\n", t - l);
        l = t;
    }
    return 0;
}