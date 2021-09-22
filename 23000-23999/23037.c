#include <stdio.h>

/*
문제 : 5자리 자연수 N이 주어질 때, 이 자연수의 각 자릿수의 5제곱의 합을 구한다.

해결 방법 : 각 자릿수를 떼어낸 다음 각각의 다섯제곱을 구하고 더하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : 서울대 2021D2 B번
*/

int pent(int x) {
    return x * x * x * x * x;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", pent(n / 10000) + pent(n / 1000 % 10) + pent(n / 100 % 10) + pent(n / 10 % 10) + pent(n % 10));
    return 0;
}