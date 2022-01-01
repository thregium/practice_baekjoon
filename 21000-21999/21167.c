#include <stdio.h>
#include <math.h>

/*
문제 : R(99 <= R <= 5281, 정수)과 S(0.009 <= S <= 1.0, 실수)가 주어질 때, 문제에 주어진 식을 통해 계산된 V를 출력한다.
이를 EOF가 나올 때 까지 반복한다.

해결 방법 : 문제에 쓰인 식대로 계산하고 계산한 값을 출력하면 된다. 반올림에 유의한다.

주요 알고리즘 : 수학, 구현

출처 : NCNA 2020 E번 // SoCal 2020 3번
*/

int main(void) {
    double r, s;
    while (scanf("%lf %lf", &r, &s) != EOF) {
        printf("%.0f\n", sqrt(r * (s + 0.16) / 0.067));
    }
    return 0;
}