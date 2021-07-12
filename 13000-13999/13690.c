#include <stdio.h>

/*
문제 : 복권의 당첨 번호와 산 복권의 번호, 산 금액이 주어질 때, 얻을 수 있는 금액을 구한다. (기준 생략)

해결 방법 : 기준에 맞게 복권의 당첨금을 확인한다.

주요 알고리즘 : 수학, 사칙연산, 구현

출처 : Brasil 2005 A번
*/

int main(void) {
    double v;
    int n, m;
    while (1) {
        scanf("%lf %d %d", &v, &n, &m);
        if (v < 0.005) break;
        if (n % 10000 == m % 10000) printf("%.2f\n", v * 3000);
        else if (n % 1000 == m % 1000) printf("%.2f\n", v * 500);
        else if (n % 100 == m % 100) printf("%.2f\n", v * 50);
        else if ((n + 99) % 100 / 4 == (m + 99) % 100 / 4) printf("%.2f\n", v * 16);
        else printf("0.00\n");
    }
    return 0;
}