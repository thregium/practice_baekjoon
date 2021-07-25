#include <stdio.h>

/*
문제 : 절댓값이 10 이하인 정수 X가 주어질 때, X가 홀수인지 짝수인지 구한다.

해결 방법 : X와 1을 and한 결과가 1이면 홀수이고 0이면 짝수이다.

주요 알고리즘 : 수학, 사칙연산?

출처 : NAQ 2013 A번
*/

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("%d is %s\n", x, (x & 1) ? "odd" : "even");
    }
    return 0;
}