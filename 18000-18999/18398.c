#include <stdio.h>

/*
문제 : 두 수 A, B(A, B <= 20000)의 합과 곱을 각각 출력한다.

해결 방법 : 합과 곱을 구해 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : Kabul 2019 7번
*/

int main(void) {
    int t, n, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            printf("%d %d\n", a + b, a * b);
        }
    }
    return 0;
}