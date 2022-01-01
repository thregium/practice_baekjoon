#include <stdio.h>

/*
문제 : N(N <= 10000)개의 P(1 <= P <= 1000, 실수)와 C(-1000 <= C <= 1000, 실수)에 대해
주어진 식 C = 100 * (P - O) / O를 만족하는 O를 출력한다.

해결 방법 : 주어진 식을 O에 대해 풀면 O = 100P / (C + 100)이라는 식이 나온다. 이를 계산하면 된다.

주요 알고리즘 : 수학

출처 : Petro 2021W7 A번
*/

int main(void) {
    int n;
    double p, c;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%lf %lf", &p, &c);
        printf("%.9f\n", (p * 100.0) / (c + 100.0));
    }
    return 0;
}