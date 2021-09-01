#include <stdio.h>

/*
문제 : N!(N <= 10000)의 일의 자리 값을 구한다.

해결 방법 : 1부터 N까지의 곱을 매번 10으로 나누어보며 풀면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : PA 2001 0-1번
*/

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r *= i;
        r %= 10;
    }
    printf("%d", r);
    return 0;
}