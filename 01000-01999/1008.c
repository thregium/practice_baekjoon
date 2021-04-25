#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
문제 : A와 B가 주어질 때 A / B를 출력한다.

해결 방법 : A와 B를 입력받고 A / B를 출력한다. 이때 자료형에 주의한다.

주요 알고리즘 : 구현?
*/

int main(void) {
     int a, b;
     double f;
     scanf("%d %d", &a, &b);
     f = (double)a / b;
     printf("%lf", f);
     return 0;
}
