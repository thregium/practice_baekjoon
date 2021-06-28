#include <stdio.h>

/*
문제 : 두 수의 제곱의 차가 N(N <= 1000)인 두 수 A, B(B < A <= 500)의 쌍의 개수를 구한다.

해결 방법 : 모든 A와 B에 대해 제곱의 차가 N인지 확인하고, 그러한 쌍의 개수를 구하면 된다.

주요 알고리즘 : 브루트 포스, 사칙연산

출처 : USACO 2007X B2번
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int a = 1; a <= 500; a++) {
        for (int b = 1; b < a; b++) {
            if (a * a - b * b == n) r++;
        }
    }
    printf("%d", r);
    return 0;
}